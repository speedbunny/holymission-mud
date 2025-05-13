#define TO this_object()

inherit "obj/npc";
     object fur;

     reset(bear) {
       ::reset(bear);

       if (!bear) {
         set_name("cave bear");
         set_alt_name("bear");
         set_short("A brown cave-bear");
         set_long("You see a cute, but dangerous-looking\n"+
                  "cavebear. She looks very hungry in your\n"+
                  "direction. Maybe she needs some food ????\n");
         set_level(60);
         set_hp(8000);
         set_ac(15);
         set_wc(80);
         set_gender(2);
         set_aggressive(1);
         set_race("bear");
         set_size(4);
         set_attacks(2);
         set_attacks_change(30);
         set_dodge(5);
         
    
            fur=clone_object("obj/armour");
            fur->set_name("fur");
            fur->set_alias("cavebear fur");
            fur->set_type("armour");
            fur->set_short("A cavebear fur");
            fur->set_long("A thick, brown and soft cavebear fur.\n"+
                          "It seems to be a great protection !\n");
            fur->set_ac(6);
            fur->set_size(4);
            fur->set_weight(5);
            fur->set_value(2000);
           move_object(fur,TO);
           command("wear fur");
          }
        }

