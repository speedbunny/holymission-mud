inherit"obj/npc";

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("bat");
    set_race("animal");
    set_short("divine bat");
    set_long("It's a divine bat. It's tough, trust me.\n");
    set_gender(3);
    add_money(1000);

    load_chat(10,
           ({ "FIUUUU ! The bat flies over your head.\n" ,
              "The bat grins evilly.\n",
              "The bat says: Come on, wimp !\n",
              "The bat yawns.\n",
           }));

   load_a_chat(10,
           ({ "The bat kicks you into you ass.\n",
              "The bat says: Ciao mortal.\n",
              "The bat says: This will be your end.\n",
              "FIUUU ! The bat flies over your head.\n",
           }));
    set_hp(2000);
    set_level(15);
    set_attacks_change(100);
    set_attacks(2);    

    set_al(10);
    set_aggressive(1);
    add_money(700);

    //set_spell_mess1("");
    //set_chance();
    //set_spell_dam();

   move_object(clone_object("/players/beardy/walhalla/obj/bclaws"),this_object());
   init_command("wield claws");
  }
}
