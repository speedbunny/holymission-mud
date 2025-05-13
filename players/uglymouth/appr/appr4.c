inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Basic LPC";
  long_desc = "Basic LPC.\n\n"
    + "LPC is the language the mud is coded in. It is derived from the\n"
    + "computer language C, and adapted for muds by the designer of the\n"
    + "first mud, Lars Pensj , hence LP-C. LPC, like C, is an object\n"
    + "oriented language. This means that everything in the mud is an\n"
    + "object: you, this room, a sword, a monster... everything. All\n"
    + "objects interact with each other by calling each other's functions.\n"
    + "You can recognize functions because they alway have a pair of\n"
    + "brackets after their name. For instance, when you move to another\n" 
    + "room, your action will call a function move() in the room object\n"
    + "you are currently in. This function willl transport you to the next\n"
    + "room. When you enter the next room, a function init() will be\n"
    + "called there. In the church this function forces you to remove any\n"
    + "hat you may be wearing (if you follow Illuvatar). Then the descrip-\n"
    + "tion and the exits must be shown by the long() function. Many\n"
    + "things can be coded there, but you'll get the idea of objects that\n"
    + "interact through functions. Imagine what happens when you buy and\n"
    + "drink a bear, or when you are fighting (complex huh?).\n"
    + "In this room too, three numbered scrolls hang on the walls. Read\n"
    + "them to gain more info on basic LPC.\n";
  dest_dir = ({
    "/players/uglymouth/appr/appr5", "next",
    "/players/uglymouth/appr/appr3", "previous",
    "/players/airborne/new/station", "leave",
  });
}

void init() {
  ::init();
  add_action("read", "read");
}

int read(string str) {
  int i;
  if(sscanf(str, "scroll %d", i) != 1) {
    notify_fail("Read which scroll?\n");
    return 0;
  }
  switch(i) {
    case 1:
      write(
  "Standard objects and inheritance.\n\n"
  + "You know from your time as a player that there are many places to go\n"
  + "(rooms), many items to gain and many monsters to encounter. All these\n"
  + "objects must be active in the computer's memory when needed. You can\n"
  + "imagine that it is very desirable to minimize the amount of memory\n"
  + "that's in use, for it also reduces the dreaded lag. You should know a\n"
  + "bit or two about memory, so you will know what you are talking about\n"
  + "when you read code, or code things yourself.\n"
  + "To reduce memory standard objects have been coded. Standard monster,\n" 
  + "weapon, armour, etc. You can find most of them in the /obj dir. When\n"  
  + "you want to use an object, both the code for that object (how does it\n"
  + "work?) and the data (name, level, weapon class, etc) must be put into\n"
  + "the memory. Now you can use clones of the standard objects. When a\n"
  + "clone is used for the first time, a master object of the thing is put\n"
  + "into memory. The master object comtains both code and data. The clone\n"
  + "only contains data. It uses the code of its master object. So a sword\n"
  + "may use the code of /obj/weapon.c, and its own data makes it a sword\n"
  + "(name) of moderate strength (weapon class 10), worth 200 gc (value).\n"
  + "You can use the code of standard objects by inheriting it. This is\n"
  + "usually done at the first line of a file.\n");
      return 1;
    break;
    case 2:
      write(
  "Using functions.\n\n"
  + "In LPC functions are defined by a name, parameter list and action\n"
  + "list. A name can be anything you like (should be obvious to what it\n"
  + "does though). The parameter list is between brackets '(parameter1, \n"
  + "paramater2, ...)'. In the case of '()' there are no parameters. Many\n" 
  + "functions return something to the calling object. The caller can use\n"
  + "that value (be it of string (text), integer (number), or other type)\n"
  + "for further processing. Functions that do not return anything are\n"
  + "called void. The action list contains the code to execute whatever it\n"
  + "is the function should do. It stands between curly brackets '{...}'.\n"
  + "An example:\n"
  + "In the shop you want to know what an item costs. A function called\n"
  + "query_value() is called, which is coded like this:\n"
  + "        query_value() { return val; }, where val could be i.e. 15 gc\n"
  + "Name: query_value, no parameters, action: returns an integer value.\n"
  + "Of course the value of the item must first have been coded, like this\n"
  + "        set_value(15) { val = 15; }\n"
  + "Name: set_value, parameter: integer 15, action: set value of 'val' 15\n"
  + "These functions are coded in the item. There are also more general\n"
  + "functions, called efuns and lfuns. Read on about them.\n");
      return 1;
    break;
    case 3:
      write(
  "Functions, efuns and lfuns\n\n"
  + "Many functions are already coded in the standard objects. When you\n"
  + "inherit these objects, you can also use these functions. So when you\n"
  + "inherit obj/weapon.c, you can just say 'set_value(15);' and the\n"
  + "standard object will do the rest for you. Simple, right?\n\n"
  + "Efuns stands for external functions, lfuns for local functions.\n"
  + "Efuns are hard coded functions, which are defined in the game\n"
  + "driver. Because of that, they can be used in the code of any\n"
  + "object. With efuns, you usually don't have the { ... } part\n"
  + "in your code, because their code is stored in the gamedriver.\n"
  + "All efuns are described in the docs.\n"
  + "Lfuns can optionally be defined by objects. They will control\n"
  + "how the object behaves _in a special situation_ (remember that\n"
  + "efuns and lfuns are reserved functions). Lfuns do need the\n"
  + "action part when coded, because, although predefined, they\n"
  + "can have different results, depending on the situation.\n"
  + "An example is get(), which can return either 1 or 0. This\n"
  + "means that the object respectively can or can't be picked up.\n"
  + "Check /doc/lfun for more detailed descriptions.\n"
  );
      return 1;
    break;
    default:
      write("The scrolls are only numbered 1, 2 and 3.\n");
      return 1;
    break;
  }
}

