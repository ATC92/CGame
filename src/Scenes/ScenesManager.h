#pragma once
///< C/C++ Lib
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
///< CGame Lib
#include "../Textures/Textures.h"
#include "../Utils/Information.h"
// #include "MenuScene.h"
//////////////////////////////////////////////////////////////////
/**
 * @brief Scenes Manager
 * 
 * ---
 * 
 * Contains:
 * 
 * @c MainMenu = 0 \\
 * @c GameState = 1 \\
 * @c OptionMenu = 2 \\
 * @c ConfigurationMenu = 3 \\
 * @c LoadScreen = 4
 * 
 * This enum defines the different scenes in the game.
 * Each scene represents a different state or screen in the game.
 */
typedef enum _scn
{
    MainMenu,
    GameState,
    OptionMenu,
    ConfigurationMenu,
    LoadScreen
}ManagerScenes;
/**
 * @brief Information of the Scene
 * 
 * ---
 * 
 * Contains:
 * 
 * @c Name          Name of the Scene \\
 * @c information   Information of the Scene \\
 * @c LOG           Log of the Scene \\
 * @c type          Type of the Scene (ManagerScenes)
 * 
 * This struct holds the information about a scene in the game.
 * It includes the name, a description, a log message, and the type of scene.
 * The type is defined by the ManagerScenes enum.
 */
typedef struct _inf
{
    char* Name;
    char* information;
    char* LOG;
    ManagerScenes type;
}InformationScene;
/**
 * @brief Scene Struct
 * 
 * ---
 * 
 * Contains:
 * 
 * @c infScene   Information of the Scene \\
 * @c Size       Size of the Scene
 * 
 * * This struct represents a scene in the game.
 * * It contains information about the scene and can hold textures or GUI elements.
 * * The `infScene` field holds the scene's metadata, while the `Size`
 * * field can be used to define the dimensions of the scene.
 */
typedef struct _scene
{
    InformationScene infScene;
    ///< Texturas o GUI
    ///< Size of the Scene
}Scene;
//////////////////////////////////////////////////////////////////
/**
 * @brief Scenes Manager Array
 * This variable holds the current scene in the game.
 * It is used to manage transitions between different scenes.
 */
extern Scene* scenes;
//////////////////////////////////////////////////////////////////
/**
 * @brief Function Prototypes for Scenes Manager
 * 
 * These functions are used to initialize scenes, create new scenes,
 * change the current scene, and retrieve information about the current scene.
 * 
 * @param void
 * 
 * @return void
 */
void InitScenes(void);
/**
 * @brief Create a new Scene
 * 
 * This function creates a new scene with the specified name, information, log, and type.
 * 
 * @param name        Name of the scene
 * @param inf         Information about the scene
 * @param LOG         Log message for the scene
 * @param type        Type of the scene (ManagerScenes)
 * 
 * @return Scene*    Pointer to the newly created scene
 * 
 * This function allocates memory for a new scene, initializes its fields,
 * and returns a pointer to the scene.
 */
Scene* CreateScene(char*,char*,char*,ManagerScenes);
/**
 * @brief Change the current scene
 * 
 * This function changes the current scene to the specified next scene.
 * 
 * @param ManagerScenes       The next scene to switch to (ManagerScenes)
 * 
 * This function updates the `scenes` variable to point to the new scene,
 * effectively changing the game's current state.
 */
void ChangeScene(ManagerScenes);
/**
 * @brief Get the current scene
 * 
 * This function retrieves the current scene's information.
 * 
 * @param Scene        The current scene (Scene)
 * 
 * @return InformationScene   The information of the current scene
 * 
 * This function returns the `InformationScene` struct associated with the current scene,
 * which includes the name, information, log, and type of the scene.
 * 
 */
InformationScene GetCurrentScene(Scene);




//////////////////////////////////////////////////////////////////
