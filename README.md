# AFTC

Anything For The Clip GDW Game



Disclaimer: This Readme is For Game Engines -> This is also the first ReadME, the updated portion is further down the page, the youtube video, and flow chart can be found below as well. Also, most of the models, sounds and textures are done by my team members if that is considered 3rd party assets.



Team: Solo

Joshua Dinata 100921955

Role: Programmer/Implementer

Responsible for programming game, including design patterns.

Video: https://www.youtube.com/watch?v=gszICSAtMa0

Flowchart: https://www.canva.com/design/DAG2X9VTx0I/uOMvB4Hcv6HCmL8dpyOAfQ/edit?utm\_content=DAG2X9VTx0I\&utm\_campaign=designshare\&utm\_medium=link2\&utm\_source=sharebutton



Gantt Chart: https://www.canva.com/design/DAG2fECsKc4/oRkXum6tjy6qf6sbiSdxcQ/edit?utm\_content=DAG2fECsKc4\&utm\_campaign=designshare\&utm\_medium=link2\&utm\_source=sharebutton



Summary: Horror game set inside an abandoned community center. Urban explorer game meant to collect requested items, all while avoiding a monster. Sound is emphasized, along with tension, atmosphere, and low poly visuals for added eerieness. The player can interact with certain objects much like in R.E.P.O, and must store items manually in a backpack. The player is meant to collect items and avoid the monster. They can escape after getting a certain amount. The player can only grab one item at a time, has a certain amount of sprinting, sightlines are important, and their sound can be detected by the monster.



Completed Design Patterns:



**Singleton:**



Used GameInstance blueprint class to emulate singleton properties.

Has function initialize start of game variables, spawn randomized objects, and has function SpawnItems.



Initialize start of game variables simply used to set all of the games starter variables whether it be for sprint speed, leaning amount, or sprint resource

drain amount etc. Makes it easier to separate from player character for clarity and can be easier for designers to access. Also that it only needs to happen once during the game's uptime.



For spawning randomized objects, it simply takes whatever inputted class and spawns them within some parameters, makes it easy and modular for designers to implement randomness of placement and type of interactable items in the world.



For function, SpawnItems, offers more technical and specific placement of items, takes spawner actors of specified objects, in this case soda cans, gets their location, and spawns them on game init.



These things are good for Singleton because they only have to happen once on game Initialization and offers potential for persistent variables such as player variables that only need one instance of the blueprint to work.



***Factory***

Factory is used to saturate the environment with items both for interactable and non-interactable in the future.



Right now it has an abstract interactable base, abstract spawner base, and concrete ones such as soda can, soda can full and empty.



BP\_IO / BP\_InteractableObject Base is used for general items, it has a default cube as its mesh and default values for physics constraints. It also has abstract variables for its model (StaticMesh) and Angular/Linear Dampening and Strength.



BP\_IO / BP\_InteractableObject Spawner has Execution that spawns an actor using abstract variables like location and the item reference.



BP\_IO / BP\_InteractableObject SodaCan is another abstract blueprint meant to differ from the default. It has lighter feeling physics and is abstract for the full and empty versions of the can



BP\_IO / BP\_InteractableObject SodaCan\_Full again has physics constraints heaver than an empty can and would set the model of its parent in its BeginPlay function



BP\_IO / BP\_InteractableObject SodaCan\_Emptied has physics constraints lighter than the full can and would set the model of its parent in its BeginPlay function



BP\_IO / BP\_InteractableObject Spawner Can is a spawner that is able to spawn either versions of soda can abstract blueprints, full or empty. This is set by the level editor/designer in the inspector.



***Command***

Command is done through the key remapping system.



First the controls portion of the UI is created from the pause menu, which is done by pressing tab, then controls.

What happens is every time its pulled up it clears the scroll box of its children, to update any new key maps, then it gets the mapping rows of the enabled actions, in this case moving, and for each one, add to an array, and from there, create each possible key bind, in this case WASD, as its own Row widget, then add to the children of the scroll box.



Each Row widget then updates its respective text fields, displaying their action and their key bind, ex. Move Foward "W".



If the input field is selected, it will listen for a key press and replace the display text and binding context of that action. For example, click -> Listen -> O Pressed -> Move forward is now "O".



The player can also press the reset button, and it will revert the bind to its default state.



It follows Command design because it encapsulates all the data of the key bind within the Row Widget, and each one is its own separate object, invoked by buttons on UI.



Plugins/DLL



Attempted to use own plugin and develop own plugin but could not get it to work. Had visual studio crash my computer, fail builds, so instead opted for FMOD usage as it will likely be needed for my GDW game anyway.



Chatbox - attempted plugin



Meant for planned feature that acted like chat room for viewers. Not a real one but displayed pre scripted messages and sent random ones.



FMOD - Used plugin



Installed and implemented FMOD files into project files, made an event in FMOD called Footstep\_wood. For now group does not have a footstep wood sound yet, so in place is a Minecraft sound. Bank made and copied to according file in content Content/FMOD/Banks. In blueprints, used play event at location FMOD node. Also tested using FMOD ambient sound on game startup.





***Final Course Project Updates***

youtube video: https://youtu.be/0lRy3glbbo4

Flow Chart: https://www.canva.com/design/DAG2X9VTx0I/uOMvB4Hcv6HCmL8dpyOAfQ/edit?utm_content=DAG2X9VTx0I&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
(Same Link as previous, just edited with new additions and updates)

Updates to Previous Patterns and Overall Game

Note: The game as mentioned is for GDW, implemented with patterns and requirements of the project, it is incomplete in terms of some mechanics, art, and sound but mechanics surrounding game engines is done.

Aesthetics
Lighting tweaked to fit horror game
Pixelation shader to simulate camera perspective
A Couple Textures implemented
A Couple sounds implemented and ties into FMOD usage
Main Menu - Bare Bones
Volume
Main HUD with corresponding UI elements - Subs -> viewers tied to collecting items

Backpack feature, to put items into to collect as the game objective

can lose by getting caught by the entity
can win after collecting all the objective items and exiting

***Command***
More keys added to binds that can be edited and reset

Backpack key

Sprint

Pause

***Singleton***
Game Instance
- Now contains volume values, since singleton is persistant between levels, it carries values from main menu and main game.

New Game instance -> Audio manager
Local to main game, holds sounds to be called by any actor in the level, only need one of these

***Factory***
Added more unique concrete instances

Basketball
Boardgame
Chips
Chocolatebar
Doll
HockeyStick

Abstract has model variable which is modified by concrete also default physics values for weight drag etc.
Each would have different models and physics values to simulate different weights and visuals.

SodaCan -> changes texture within its concrete blueprint using texture modifications and parameters, simulating different brands for the soda can, indicating the need for different factory items. (Differing spawning conditions and randomization).

Plugin/DLL
Could not get my own plugins to work. Visual studio was not working no matter what I did, also trying to clean my computer by, resetting, full wipe cleaning my computer, updating, all didn't work so I defaulted back to FMOD. With FMOD I was able to add more sounds
but would not be present in the build, because I can't compile the DLLS needed. It is better than the built in Unreal Sound I found, as it was more surround sound-like, and had more options for tweaking and editing. For example the wood footsteps sound I have were edited in FMOD to be spliced into single varying steps.

***New Additions***

**Optimization**

Priority: Object Pooling

For object pooling, I have it linked to the interactable item system I have. Before I had it spawn and destroy upon being put in the player's backpack. Now it simply disables it and puts it outside of the map

Enabled Array - Array to hold items enabled in the map

Available array - array to hold items available to be re enabled

EnableItem Function - searches items in available array, removes it from available array, adds it to enabled array and spawns it where defined

DisableItem Funciton - takes inputted item, removes from enabled array, spawns outside of map and adds to available array for future spawning

Chose object pooling for this because if the spawning system had to generate new items and destroying constantly, it would just displace it for future use later.

Dirty Flag - I do have implementation of dirty flag, but I deemed it not that good of use or impactful enough. So I decided to focus more on object pooling in this readme and the video. As mentioned in the video, used in the volume slider, and would mark the volume as dirty whenever the slider was moved, and only assigned to the singleton persistent across levels when needed. Also only checked every 0.3 seconds rather than event tick, even only a little, improving performance.

**State**

The use of state is in the Entity - the monster in the game.

I used state because I think it is conventional with "AI" type entities in games.

For mine I have

Wander - wanders to random target points

Investigate - whenever the monster is in range to hear sound

Alert - Whenever the player is in vision

Transform - Whenever the player stays within vision for x amount of time

Chase - Chases the player

Search - if LOS is broken goes to last seen position of the player

Before I had it so that it went through a sequence every frame using event tick. Now I have a state flow, where it would only pulse one single execution and would change state when applicable. Also helping with performance.

**Profiling**

In my video, I provided an attempted trace using Unreal Insights which didn't pan out like I wanted, but I did use the commands and changes to improve FPS which I had proof of in the screenshots I had in testing.

Camera - Disabled motion blur
Used commands to tone down graphics, lighting, anti aliasing, ray tracing listed here

Lumen Stuff
r.Lumen.HardwareRayTracing 0
r.RayTracing.ForceAllRayTracingEffectsOff 1
r.Lumen.ScreenProbeGather.Quality 2
r.Lumen.DiffuseIndirectQuality 2
r.Lumen.Reflections.Quality 2

disable TSR
r.AntiAliasingMethod 1
Switched anti aliasing method

Turn Motionblur off

Along with this, I had also mentioned some improvements with Dirtyflag and State but those shouldn't count for Profiling regarding the assignment instructions.

