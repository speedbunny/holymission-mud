#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
     
 
    move_object(clone_object("/players/alex/armour/bboots"),ME);
    command("wear ",ME);
    set_name("elf");
    set_alias("elf");
    set_short("A sick elf");
    set_long("The elf looks very sick but harmless.\n");
    set_gender(1);
    set_level(1);
    set_aggressive(0);
    set_al(50);
}
init() {
 ::init();
 add_action("say","say");
 add_action("help","help");
 add_action("look","look");
}
              
              
int say(string str)   {
  switch(str) {
    case "dreadforest":
        write ("The elf is delirious and attacks you.\n");
        set_aggressive(1);
        return 1;
             }  
 
  switch(str) {
    case "help":
        write("The sick elf says: Please I have failed my master, help him.\n");
        return 1;
        }
 
 switch(str) {
    case "help elf":
        write("The sick elf says: Please I have failed my master, help him.\n");
        return 1;
        }     
 
  switch(str) {
    case "master":
        write("The sick elf says:My master Shal~Manthues, was cursed by Highlord Alex\n"+
              "of the Cathans to eternal torment of the undead.  He is in a tomb on the\n"+
              "east side of the dreadforest.\n");
        return 1;
        }
 
}
 
int look(string str)  {
 switch(str){   
  case "at elf":
 
        write("The sick elf is muttering please say you will help me.\n");
        return 1;
        }
         
}
