![image](https://github.com/hunteramac/UE5_Latent_BP_Dialog_Choices/assets/16585398/00534255-8fb6-4629-b561-3577fd3a1906)Top level is **Source** inside ue5 project. Developed inside project with name **c2077approx**.

Project code demonstrates how very simple custom asyncronous bp and subsystems can be defined for a useful application that can't be readily acheived with blueprint exclusively.

Since WIP not a plugin yet. If you want to use, drop the C++ cpp and header files into your project/ Source in respective public private folders and compile.

Protoype is implementation of asynchronous blueprint node and programming subsystems that:
- takes in a list dialog choices in the blueprint editor
- exposes the list with a subsystem so any UI implementation can grab and display list to player
- exposes a callback for UI o cause asynchronous BP node to return a result when a player choice is detected.

Thereby enabling graph/node based design of dialog trees quickly inside blueprint.
Treats UI like a blackbox for maximum compatibility with UI implementations. User must define their own UI. Functionality provided here is communication and editor flow/organization.

Why is this useful? Pure BP implementation relies on UI Event dispatcher which requires constant rebinding events. Results in a mess/hassle for designer in blueprints. A unique event per dialog choice.
This fixes that and makes blueprint usage simpler.

Implementation is very simple by design. Intent is to cut down details needed for readily understanding UE5 async node definition and subsystems. This is an extendable template to modify as needed.

Note that an alternative communication/organization method which is much more elegant(and complicated requiring C++ knowlege) is FlowGraph which seems to be a superior method for large projects to avoid blueprint 'Flying Spaghetti Monsters'.
https://github.com/MothCocoon/FlowGraph
I needed something messier to prototype small projects with.

Prototype's current usage(WIP) (On right is nodes to place inside UI widget):
![image](https://github.com/hunteramac/UE5_Latent_BP_Dialog_Choices/assets/16585398/daed3c8c-f52f-410f-b274-46717ee10fcc)
Requirements:
- You have a UI implementation that can take in a text array, and detect a player choice
- Use the subsystem provided 'ChoiceUIGameInstanceSubsystem' (drop node into blueprint) to get out 'DisplayActions' passed to async 'WaitForChoiceNode'
- Use subsystems's 'UIUserChoice' method to trigger return of async node. (place in UI BP's player input detection)

Example with a very basic UI implementation(Done inside level blueprint):
![image](https://github.com/hunteramac/UE5_Latent_BP_Dialog_Choices/assets/16585398/4c0a7d31-39c9-46ef-9ca4-5a6c6f05ed60)


The main wait on choice and UI methods and choice switch can be collapsed into a macro or node for streamlined organization in blueprint editor. Example:
![image](https://github.com/hunteramac/UE5_Latent_BP_Dialog_Choices/assets/16585398/02789dba-6a13-42a9-9df0-63b6828493e0)


Example of method I had been using purley in blueprints. Requires unique events per choice. Awkward designer useage.
![image](https://github.com/hunteramac/UE5_Latent_BP_Dialog_Choices/assets/16585398/91c1961f-075b-419d-a3b2-364769423a0f)


Implementation is based on Epic Games Lyra Shooter starter project which contains  a very nuanced implementation in ShowConfirmationMenu. Project retroffited functionality for use in specific application.
See https://www.youtube.com/watch?v=p_biHD6QZvA (Not by me) for a good overview of ShowConfirmation menu

Additionally functionallity in works
- Async BP play sequence node, continues blueprint execution after sequence finishes playing without needing to bind an event handler
