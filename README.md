# AFTC

Anything For The Clip GDW Game



Disclaimer: This Readme is For Game Engines



Team: Solo

Joshua Dinata 100921955

Role: Programmer/Implementer

Responsible for programming game, including design patterns.



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



Factory:

Factory is used to saturate the environment with items both for interactable and non-interactable in the future.



Right now it has an abstract interactable base, abstract spawner base, and concrete ones such as soda can, soda can full and empty.



BP\_IO / BP\_InteractableObject Base is used for general items, it has a default cube as its mesh and default values for physics constraints. It also has abstract variables for its model (StaticMesh) and Angular/Linear Dampening and Strength.



BP\_IO / BP\_InteractableObject Spawner has Execution that spawns an actor using abstract variables like location and the item reference.



BP\_IO / BP\_InteractableObject SodaCan is another abstract blueprint meant to differ from the default. It has lighter feeling physics and is abstract for the full and empty versions of the can



BP\_IO / BP\_InteractableObject SodaCan\_Full again has physics constraints heaver than an empty can and would set the model of its parent in its BeginPlay function



BP\_IO / BP\_InteractableObject SodaCan\_Emptied has physics constraints lighter than the full can and would set the model of its parent in its BeginPlay function



BP\_IO / BP\_InteractableObject Spawner Can is a spawner that is able to spawn either versions of soda can abstract blueprints, full or empty. This is set by the level editor/designer in the inspector.



Command:

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



