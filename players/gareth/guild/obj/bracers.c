#include "/players/gareth/define.h"
inherit "/obj/armour";

reset(arg) {
     ::reset(arg);
     if(arg) return;
         set_name("bracers of defense");
         set_alias("bracers");
         set_short("Bracers of Denfense");
         set_long("A pair of arm guards that have pictures of \n"+
		  "the agile cheetah engraved on them. They feel\n"+
		  "as light as a feather\n");
         set_type("arm");
         set_ac(1);
         set_arm_light(1);
         set_weight(1);
         set_value(6000);
	 modify_stat(1,2);
	
  }

wear(arg) {
     if(TP->query_npc()) return ::wear(arg);
     if(TP->query_gender() !=2) {
       write("You may bitch like a woman, But yer NO lady!! \n");
       return 1;
     }
	return ::wear(arg);
}

