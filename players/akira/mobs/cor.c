inherit "obj/monster";
reset(arg){
::reset(arg);

set_name("Corinthian");
set_alt_name("cor");
set_alias("corinthian");
set_short("Corinthian");
set_long("This is the legendary Corinthian. It is said that he is the\n"+
         "oldest and wisest Vagabond there is. Legends say that when\n"+
         "he was young, he went to a castle that the gods no longer visit.\n"+
         "There he dark a wine that most gods say is to strong. He was\n"+
         "then told three songs and nine chants eighteen charms and nine\n"+
         "times nine names. He can tell you of weapons, temples, spheres,\n"+
         "and timetravel. All you have to do is say the right topic.\n");
set_level(100);
set_ac(100);
set_wc(100);
set_number_of_arms(2);
}
init(){
  ::init();
            add_action("_weapons", "weapon");
            add_action("_temples", "temples");
            add_action("_spheres", "spheres");
            add_action("_timetravel", "timetravel");
            add_action("_say", "say");
}

_say(str){
if(str== "weapons"){
write("Corinthian says: Let me think. The most powerful weapon I can think\n"+
      "                 of was said to be wielded by the very first of the\n"+
      "                 Vagabonds. It was said that she wielded reality as\n"+
      "                 a weapon! Unfortunately she was killed during the\n"+
      "                 Summoner Wars, and her weapons lost with her. To\n"+
      "                 bad the secret of 'timetravel' was lost over the\n"+
      "                 years, someone might be able to go back and save\n"+
      "                 the secrets of that weapon.\n");
return 1;
}
if(str== "spheres"){
write("Corinithan says: Legends tell of a Sphere created long ago that\n"+
      "                 could take a person threw time and space. Alas\n"+
      "                 it was also lost many years ago. It is said that\n"+
      "                 after the Summoner Wars it was hidden in reflection\n"+
      "                 and that reflection was hidden in a temple. It is\n"+
      "                 important to remember that if you do not remeber\n"+
      "                 your mistakes you will repeat them.\n");
return 1;
}
if(str== "temples"){
write("Corinthian says: The Temple of the Fallen was build after the\n"+
      "                 Summoner Wars to honor those who died in the\n"+
      "                 War. What is not commonly known is that many\n"+
      "                 objects of great power were locked away in it\n"+
      "                 because man was not yet ready for there awsome\n"+
      "                 powers. However the location of this temple is\n"+
      "                 no known. The last people who went looking for\n"+
      "                 it were said to have all been killed by Khan and\n"+
      "                 his Barbarian Hordes. Khan said that no man may\n"+
      "                 enter the barbarian plains uninvited.\n");
return 1;
}
if(str== "timetravel"){
write("Corinthian says: Well I myself don't know how to do it, and even\n"+
      "                 if i did, I would not teach one so young. The only\n"+
      "                 way I can see you doing it, is to find the Cronus\n"+
      "                 Sphere. It is said that it can take a person back\n"+
      "                 in time. I will tell you this, time does not\n"+
      "                 begin with an e.\n");
return 1;
}
}
