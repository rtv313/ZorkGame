# ZorkGame
Master 1st Project testing 
###Author
Raul Rodolfo Trevino Vazquez
###About:
This Zork game is the first project for the UPC VideoGames Master Degree.In this game you are a detective that must find who is the murder by asking the witness,suspects, and analyzing the evidence,once you find everything you must decide who is the murderer of Sarah
beware you can sentence the suspect at any moment, so before dictate the sentence be sure who is the true murder.

###Link Github
https://github.com/rtv313/ZorkGame - automatic!
[GitHub](https://github.com/rtv313/ZorkGame)


<a href="https://github.com/rtv313/ZorkGame" class="btn">View on GitHub</a>

###Link Licence
https://github.com/rtv313/ZorkGame/blob/master/LICENSE - automatic!
[License](https://github.com/rtv313/ZorkGame/blob/master/LICENSE)

###Instructions:

* "Help" = Display Instrucctions
* "Rooms" = Display a list of the rooms
* "Quit" = Close the game
* "Look" = Show you a list of the characters and stuffs in the room
* "Inventory" = Displays the items you have
* "Look" {ObjectName} ,this allows you to look inside Containers
* "Move" {RoomName} ,this allows you to move between rooms
* "Take" {ItemName} ,this allows you to take an item in the room
* "Take" {ItemName} in {ItemName} ,this allows you to take an item inside another item
* "Drop" {ItemName} ,this allows you to drop an item in the room
* "Equip" {ItemName} ,this allows you to equip an item from you're inventory
* "UnEquip" {ItemName} ,this allows you to Unequip an item and return it to the inventory
* "Talk" {Character Name} ,this allows you to start a conversation with a character who is in the same room
* "Sentence" {SuspectName} ,this allows you to end the game choosing who is the murder

#####PLAYER TOOLS:

You must have and equiped this items before you can use them.

* "PDA" "SCAN" {EVIDENCE/CHARACTER} ,this allows you to search more info about characters or evidence and add a note to your notebook,HINT:The object must be in the room for scan not inside other object
* "Notebook" "READ" {NoteName} ,this allows you to read a specific note
* "Notebook" "LIST" "NOTES" ,Display all the notes in you're Notebook

###Walkthrough

* Look
* Rooms
* Talk officer
* input 0
* Move office
* Look
* Take PDA
* Take Notebook
* Move Hallway
* Move Suspects
* Look
* Talk john
* inputs 0,1,2
* Equip PDA
* PDA scan john
* Talk David
* inputs 0,1,2
* PDA scan david
* Move hallway
* Rooms
* Move evidence
* Look
* Look evidencebox
* Take pistol in evidencebox
* Take pictures in evidencebox
* Equip PDA
* Drop pistol
* PDA scan pistol
* Drop Pictures
* PDA scan pictures
* Equip Notebook
* Notebook list notes
* Notebook read pistol
* Notebook read pictures
* Move hallway
* Move Forense
* Look
* Talk Jessica
* input 0
* Equip PDA
* PDA Scan sarah
* Move hallway
* Move Witness
* Look
* Talk Charles
* inputs 0,1,2
* Talk judith
* inputs 0,1,2
* Move hallway
* Move suspects
* Sentence john || Sentence David
