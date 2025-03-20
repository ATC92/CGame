#include "LoadTextures.h"
/**
 * @brief Loads and parses a JSON file into a cJSON object.
 * 
 * This function reads a JSON file from the given path, allocates memory for its content, 
 * and parses it into a `cJSON` object.
 * 
 * @param patch Path to the JSON file.
 * 
 * @return cJSON* Pointer to the parsed JSON object, or `NULL` if an error occurs.
 * 
 * @note The caller is responsible for freeing the returned `cJSON*` using `cJSON_Delete()`.
 * 
 * @warning If the file cannot be opened, memory allocation fails, or parsing fails, 
 *          the function returns `NULL`.
 * 
 * Example usage:
 * @code{.c}
 * cJSON* json = Load_cJSON("config.json");
 * @endcode
 */
cJSON* Load_cJSON(const char* path)
{
    FILE *file = fopen(path, "r");                                  ///< Creating the FILE
    if(!file) 
    { 
        perror("Error, json can't open"); 
        return NULL; 
    } 

    ///< Looking for the size of the json. 
    fseek(file,0,SEEK_END); 
    long fSize = ftell(file); 
    rewind(file);

    char* entityData = (char*)calloc(fSize + 1, sizeof(char));          ///< Create space for the data.
    ///< Validate if the malloc take the memory to allo cate
    if (!entityData) 
    { 
        perror("Error allocating memory"); 
        fclose(file); 
        return NULL; 
    } 

    fread(entityData,1,fSize,file);                                 ///< Read .JSON
    fclose(file);                                                   ///< Close the FILE

    ///< Parse the JSON file
    cJSON *json = cJSON_Parse(entityData);                          ///< Create cJSON Parse
    free(entityData);                                               ///< Char* mapData
    if (!json)
    {
        printf("Error, the JSON can't parse: %s\n",cJSON_GetErrorPtr());
        cJSON_Delete(json); 
        return NULL;
    }
    return json;
}
/**
 * @brief Process Tile
 * 
 * This function process the entity to load the textures from the cJSON
 * 
 * @param item          Item type void*.
 * @param json          Parsed cJSON object.
 * 
 * @note The @n `void*` will be cast as a @n `sTile*`.
 * 
 * @return @n `void`
 */
void ProcessTile(void* item, const cJSON* json)
{
        ///< Init temp declaration
    sTile* tile = (sTile*)item;
    cJSON* Name = cJSON_GetObjectItemCaseSensitive(json,"Name");
    cJSON* ID = cJSON_GetObjectItemCaseSensitive(json, "ID");
    cJSON* patchTexture = cJSON_GetObjectItemCaseSensitive(json, "tPatch");
    ///< Init temp declaration
    if (Name && cJSON_IsString(Name) && ID && cJSON_IsNumber(ID) && patchTexture && cJSON_IsString(patchTexture))
    {
        tile->name = strdup(Name->valuestring);                         ///< Duplicate Name
        tile->ID = ID->valueint;                                        ///< Copy the ID of the JSON Tile
        tile->texture = LoadTexture(patchTexture->valuestring);         ///< LoadTexture Vector2D Raylib
        tile->parseTileGen = cJSON_Duplicate(json,1);                   ///< Duplicate the cJSON struct, if Free(json), the `tile->parseJson_Map` lost.
    }
}
/**
 * @brief Process Entity
 * 
 * This function process the entity to load the textures from the cJSON
 * 
 * @param item          Item type void*.
 * @param json          Parsed cJSON object.
 * 
 * @note The @n `void*` will be cast as a @n `tEntity*`.
 * 
 * @return @n `void`
 */
void ProcessEntity(void* item, const cJSON* json)
{
    ///< Init temp declaration
    tEntity* entity = (tEntity*)item;
    cJSON* Name = cJSON_GetObjectItemCaseSensitive(json,"Name");
    cJSON* ID = cJSON_GetObjectItemCaseSensitive(json, "ID");
    cJSON* patchTexture = cJSON_GetObjectItemCaseSensitive(json, "tPatch");
    ///< Validation
    if (Name && cJSON_IsString(Name) && ID && cJSON_IsNumber(ID) && patchTexture && cJSON_IsString(patchTexture))
    {
        entity->name = strdup(Name->valuestring);                       ///< Duplicate Name
        entity->ID = ID->valueint;                                      ///< Copy the ID of the JSON Tile
        entity->Texture = LoadTexture(patchTexture->valuestring);       ///< LoadTexture Vector2D Raylib
        entity->parseJson_Entity = cJSON_Duplicate(json,1);             ///< Duplicate the cJSON struct, if Free(json), the `tile->parseJson_Map` lost.
    }
}
/**
 * @brief Load all textures from cJSON.
 * 
 * This is a generic function that processes a JSON object and allocates 
 * memory for a structure.
 *
 * @param json           Parsed cJSON object.
 * @param key            Key used to extract data from cJSON.
 * @param struct_size    Size of the struct to allocate.
 * @param max_items      Maximum number of items to allocate. \n
 *                       @n `Example: StructName* ptr = malloc(max_items * struct_size);`
 * @param process_func   Function pointer to process each item. \n
 *                       @n `Signature: void* ProcessItemFunc(const cJSON*).`
 *  
 * @return @n `void*`         Pointer to the allocated structure.
 */
void* LoadTexturesFromJSON(const cJSON* json, const char* key, size_t struct_size, int max_items, ProcessItemFunc processFunc)
{
    void* items = calloc(max_items, struct_size);
    if (!items) {
        perror("Error allocating memory");
        return NULL;
    }

    cJSON* jItems = cJSON_GetObjectItemCaseSensitive(json, key);
    if (!jItems || !cJSON_IsObject(jItems))
    {
        printf("\n\nError: JSON key '%s' is missing or is not an object.\n", key);
        free(items);
        return NULL;
    }
    cJSON* _item;
    int i = 0;
    cJSON_ArrayForEach(_item, jItems)
    {
        if (i >= max_items) break;                              ///< Avoid Overflows
        processFunc( (char*)items + (i * struct_size), _item);
        i++;
    }

    if (i == 0) {
        printf("\n[ERROR] No tiles were processed!\n");
        free(items);
        return NULL;
    }
    return items;
}
/**
 * @brief Generate an array of tiles (sTile*).
 * 
 * Parses a cJSON object to create an array of tiles.
 *
 * @param json Parsed cJSON object.
 * @return @n `sTile*` Pointer to the generated array of tiles.
 */
sTile* LoadMapTextures(const cJSON* json)
{
    return (sTile*)LoadTexturesFromJSON(json, "tiles", sizeof(sTile), 6, ProcessTile);
}
/**
 * @brief Generate an array of textures (tEntity*).
 * 
 * Loads textures from a JSON file and creates an array of entities.
 * 
 * @param Patch Path to the JSON file containing the configuration.
 * @param key Key identifying the entity to load from the JSON.
 * @return @n `tEntity*` Pointer to the generated array of textures.
 */
tEntity* GenTextureEntity(const char*path, const char*key)
{
    cJSON* json = Load_cJSON(path);
    tEntity* eTemp = LoadTexturesFromJSON(json, key, sizeof(tEntity), 6, ProcessEntity);
    //cJSON_Delete(json);
    return eTemp;
}
/**
 * @brief Render all the map from the Parse cJSON
 * 
 * @param RenderData*           ///< 
 */
void RenderTileMap(RenderData* _mD, MapEnum _slct)
{
    int texture_index_x=0;
    int texture_index_y=0;
    int tileset_columns = 10;
    for (int y = 0; y < _mD->mapsData[_slct].height; y++)
    {
        for (int x = 0; x < _mD->mapsData[_slct].width; x++)
        {
            int tile_id = _mD->mapsData[_slct].data[y][x];

            int texture_index_x = tile_id % tileset_columns;
            int texture_index_y = tile_id / tileset_columns;

            Rectangle source = {
                (float)texture_index_x * TILE_WIDTH,
                (float)texture_index_y * TILE_HEIGHT,
                (float)TILE_WIDTH,
                (float)TILE_HEIGHT
            };

            Rectangle dest = {
                (float)(x * TILE_WIDTH),
                (float)(y * TILE_HEIGHT),
                (float)TILE_WIDTH,
                (float)TILE_HEIGHT
            };

            Vector2 origin = {0 , 0};

            if (tile_id >= 0)
            {
                DrawTexturePro(_mD->sTilesData[tile_id].texture, source, dest, origin, 0.0f, WHITE);
            }
        }
    }
}
/**
 * 
 */
void RenderPlayer(const Entity eplayer, const Camera2D _cam)
{
    // DrawTexture(eplayer._tEntity[eplayer._eLook].Texture, eplayer._player.position.x, eplayer._player.position.y, WHITE);

    Rectangle source = 
    { 
        (float)1 * TILE_WIDTH,
        (float)1 * TILE_HEIGHT, 
        (float)TILE_WIDTH, (float)TILE_HEIGHT 
    };

    Rectangle dest =
    { 
        floorf(eplayer._player.position.x), 
        floorf(eplayer._player.position.y), 
        (float)TILE_WIDTH, (float)TILE_HEIGHT 
    };

    Vector2 origin = { 0, 0 };

    DrawTexturePro(eplayer._tEntity[eplayer._eLook].Texture, source, dest, origin, 0.0f, WHITE);
}

