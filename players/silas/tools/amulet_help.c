version() { return "Amulet of Wizardhood Help. Version 3.0.5"; }

amulet() {
  write(version() + "\n");
  write("\n");
  write("Help is available on the following commands:\n\n");
  write("    alarm        *  exec            make         *  stat     \n");
  write(" *# call            fear         *  omo          *  stopfight\n");
  write(" *# callout      *  fname        *  oto             ti       \n");
  write("    clon            help          # pose          # telllog  \n");
  write("  # desc         *# in            # secho        *  wipe     \n");
  write("  # eall            light         # selec           zone     \n");
  write(" *  ensoul       *  linv          # selsh                    \n");
  write("    epo          *  long         *  sgo                      \n");
  write("\n");
  write("* - command uses object referencing. See obj_ref\n");
  write("# - command uses string modification. See str_mod\n");
  return 1;
  }

obj_ref() {
  write("Object Referencing.\n\n");
  write("Many commands have objects as arguments. To give a reference to\n");
  write("a unique object, an object-descriptor system has been used.\n");
  write("The following rules are obeyed:\n\n");
  write("  1) Names of local objects (ones in or around the wizard),\n");
  write(" living objects, or object filenames can be used.\n");
  write("  2) Indexing is available, using \"%\", ie sword%2 is the second\n");
  write("sword.\n");
  write("  3) Objects within another namable object can be referenced,\n");
  write("using \">>\", ie, sword%2>>/obj/player%67 is the second sword in\n");
  write("player%67.\n");
  write("  4) Environments can be referenced, using \"ENV:\", \"env:\", or\n");
  write("\"<<\" (opposite of \">>\"). Thus, <<bubbs is the environment\n");
  write("that contains Bubbs.\n");
  write("  5) Some special words are available. \"me\" means this player,\n");
  write("\"this\" means the amulet itself, \"here\" means the environment\n");
  write("of the player.\n");
  return 1;
  }

str_mod() {
  write("String Modification.\n\n");
  write("Man commands use string modification, for putting in special\n");
  write("characters not normally accessible from command arguments,\n");
  write("ie \"\\n\". To use this, just enter \"\\n\" in the command, the\n");
  write("amulet will interpret. Also, \"\\t\" works in a similar manner.n");
  return 1;
  }

alarm() {
  write("Alarm\n\n");
  write("The alarm function is used to set, monitor and turn off a timed\n");
  write("alarm.\n");
  write("A null argument will give the time the alarm is set for, (or tell\n");
  write("you that no alarm is set.\n");
  write("The argument \"off\" will turn off the alarm.\n");
  write("To set the alarm, just give the alarm time as the argument,\n");
  write("in the form hh:mm in 24 hour format, ie alarm 23:44.\n");
  write("\nSee also: ti, zone\n");
  return 1;
  }

call() {
  write("Call\n\n");
  write("The call function is similar to that on the tracer, but it is\n");
  write("more advanced. Object referencing is used for identifying the\n");
  write("object to be called, and string modification can be used for\n");
  write("argument. Note also the following:\n");
  write("If the argument is a number, it is assumed to be type integer,\n");
  write("you can specify a string type by giving the argument a prefix\n");
  write("of \"$$\", ie \"$$45\" is treated as \"45\".\n");
  write("If the argument is an object, you can use object referencing by\n");
  write("prefixing the argument with \"##\", ie \"##bag>>bubbs\".\n");
  write("The returning value of the function call is written on screen\n");
  write("together with the type of variable.\n");
  write("\nSee also: callout\n");
  return 1;
  }

callout() {
  write("Callout\n\n");
  write("The callout function is similar to the call function, except that\n");
  write("an extra argument is put in, called the delay.\n");
  write("ie: \"callout 4 here long demon\" calls long in this room with\n");
  write("argument \"demon\" in four seconds time.\n");
  write("\nSee also: call\n");
  return 1;
  }

clon() {
  write("Clon\n\n");

  write("Very much like standard wizard command \"clone\", but without\n");
  write("access checking.\n");
  return 1;
  }

desc() {
  write("Desc\n\n");
  write("Set the extra_look in the amulet. String modification is used.\n");
  return 1;
  }

eall() {
  write("Eall\n\n");
  write("Similar to standard wizard command \"echoall\", but string\n");
  write("modification is used. Also, if shouts are normally logged, this\n");
  write("will not be.\n");
  write("\nSee also: epo, pose, selsh\n");
  return 1;
  }

ensoul() {
  write("Ensoul\n\n");
  write("clone and move a \"obj/soul\" to the object described in the\n");
  write("argument.\n");
  return 1;
  }

epo() {
  write("Epo\n\n");
  write("Shout a silly message to the world about Eeps.\n");
  write("\nSee also: eall, pose, selsh\n");
  return 1;
  }

exec() {
  write("Exec\n\n");
  write("Very similar to standard wizard command \"force\",\n");
  write("but it uses string modification.\n");
  return 1;
  }

fear() {
  write("Fear\n\n");
  write("Cast a \"fear\" spell onto a living object.\n");
  return 1;
  }

fname() {
  write("Fname\n\n");
  write("write the filename of an object using object referencing.\n");
  return 1;
  }

help() {
  write("Help\n\n");
  write("Gives the help pages for the Amulet of Wizardhood as well as the\n");
  write("game help pages.\n");
  write("For a list of help topics on the Amulet, type \"help amulet\".\n");
  return 1;
  }

in() {
  write("In\n\n");
  write("Simular to the basic wizard command \"in\", but uses object\n");
  write("referencing and string modification.\n");
  return 1;
  }

light() {
  write("Light\n\n");
  write("General light manipulation command. Integral argument is set as\n");
  write("this objects light value. Also writes new light value.\n");
  return 1;
  }

linv() {
  write("Linv\n\n");
  write("Lists the inventory of an object using object referencing.\n");
  write("filenames are given as well as short descriptions, if there is\n");
  write("no short description, the extra_look is written instead.\n");
  return 1;
  }

long() {
  write("Long\n\n");
  write("Very simple command that calls the long description of the object\n");
  write("referred to.\n");
  return 1;
  }

make() {
  write("Make\n\n");
  write("The make command takes several arguments, \"monster\", \"weapon\",\n");
  write("\"armour\", and \"treasure\". An object is cloned from the\n");
  write("relevent file in \"/obj\" and given an id of its type.\n");
  write("Finally, the object is dumped into the players inventory,\n");
  write("where it can be shaped using the \"call\" command.\n");
  write("\nSee also: call, clon\n");
  return 1;
  }

omo() {
  write("Omo\n\n");
  write("This command takes an argument with two objects to be referenced.\n");
  write("The first object is then moved into the second object using\n");
  write("\"move_object\".\n");
  write("\nSee also: oto\n");
  return 1;
  }

oto() {
  write("Oto\n\n");
  write("This command, similar to omo, uses \"transfer\" rather than\n");
  write("\"move_object\", and thus takes care of weights and so forth.\n");
  write("The successfullness of the operation is written afterwards.\n");
  write("\nSee also: omo\n");
  return 1;
  }

pose() {
  write("Pose\n\n");
  write("The pose command shouts to the world a string modified by string\n");
  write("modification in a style similar to the general command \"pose\".\n");
  write("\nSee also: eall, epo, selsh\n");
  return 1;
  }

secho() {
  write("Secho\n\n");
  write("Very similar to the standard wizard command \"echo\".\n");
  write("\nSee also: selec\n");
  return 1;
  }

selec() {
  write("Selec\n\n");
  write("Like the \"echo\" command, but takes two arguments, the first\n");
  write("should be a living object in your current room.\n");
  write("All living object except you and the named one will recieve the\n");
  write("string modified rest of argument.\n");
  write("\nSee also: selsh\n");
  return 1;
  }

selsh() {
  write("Selsh\n\n");
  write("Similar to the \"eall\" command, and also to the \"selec\"\n");
  write("command. This command will tell everyone in the game a message\n");
  write("except yourself, and a named player.\n");
  write("\nSee also: eall, epo, pose, selec\n");
  return 1;
  }

sgo() {
  write("Sgo\n\n");
  write("Similar to the wizard command \"goto\", the \"sgo\" command uses\n");
  write("object reference and leaves no messages heralding your exit or\n");
  write("entrance.\n");
  write("\nSee also: omo, oto\n");
  return 1;
  }

stat() {
  write("Stat\n\n");
  write("Using object reference, this command will display the \"stats\" of\n");
  write("of a particular object. In the case that the object is living, the\n");
  write("command defaults to the ordinary \"stat\" command.\n");
  return 1;
  }

stopfight() {
  write("Stopfight\n\n");
  write("This command will stop all fights in a particular object, given\n");
  write("through object referencing. If no argument is given, the present\n");
  write("location of the player is assumed.\n");
  return 1;
  }

ti() {
  write("Ti\n\n");
  write("Displays the current game time.\n");
  write("\nSee also: alarm, zone\n");
  return 1;
  }

telllog() {
  write("Telllog\n");
  write("Using string modification, this command will leave a message in a\n");
  write("named log file in the \"log/\" directory.\n");
  return 1;
  }

wipe() {
  write("Wipe\n\n");
  write("The \"wipe\" command is similar to the standard wizard command\n");
  write("\"destruct\", except that \"wipe\" uses object refernce.\n");
  write("If the argument \"all\" is given, all objects in the players\n");
  write("inventory except the amulet and any object with id \"soul\" will\n");
  write("be destroyed.\n");
  write("The \"all\" can be used as a primitive wildcard for destroying\n");
  write("objects in other inventories. For example \"wipe all>>bubbs\"\n");
  write("will destroy all objects in Bubbs' inventory with the same\n");
  write("exceptions as above.\n");
  return 1;
  }

zone() {
  write("Zone\n\n");
  write("This command lets you add or take a time difference from the game\n");
  write("time, thus allowing players in a different time zone to alter the\n");
  write("clock to their own time.\n");
  write("\nSee also: alarm, ti\n");
  return 1;
  }
