Top level is Source inside ue5 project.

Goal is to implement an Asynchronous Blue print node that 
- takes in a list dialog choices
- communicates to UI to show choices to player
- waits for UI to detect player choice
- returns choice on latent exec pin for designer

Mock up of usage:
![image](https://github.com/hunteramac/UE5_Latent_BP_Dialog_Choices/assets/16585398/cca92ff0-48a1-4c27-aaee-8eb306ba1ac3)

Mock up created by using highly inefficent Blueprint work around involves unique defintion of events binding to UI button event. 
![image](https://github.com/hunteramac/UE5_Latent_BP_Dialog_Choices/assets/16585398/91c1961f-075b-419d-a3b2-364769423a0f)

The goal is to use UE5 behavior only definable in C++:
- Asyncronous Nodes
- Game Subsytems (communication)

To acheive ideal result that streamlines designer workflow in editor. One node that talks to UI, passes it choices. Presents choices.
And returns execution for designer to handle.

Epic games Lyra Shooter starter project contains baseline implementation in ShowConfirmationMenu. Project is retrofitting functionality for use in specific application.

Result intended to be rough, ideal for prototyping.
