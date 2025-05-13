

#define SUPERWIZ ({"haplo","tatsuo","gandalf","dalamar"})

inherit "room/room";

void reset(int flag) 
{
 object board, tatboard, spherea, sphereb; /*installed chat board and spheres*/

  if(flag == 0) 
  {
    set_light(1);
    dest_dir=({ "players/haplo/workroom","hap",
                "players/tatsuo/workroom","tat"
                 });
    short_desc="Tatsuo's and Haplo's private study";
    long_desc=
     "This is Tatsuo's and Haplo's private study few are permited here and only if\n"+
     "Tatsuo and Haplo. You can see walls lined with many shelves each filled\n"+
       "with large volumes of ancient books with colorful bindings.\n"+
     "Ther are comfortable leather chairs to sit and read or study\n"+
     "whichever you may desire to do. The curtains are rich deep maroon velvet\n"+
     "The tables in the room are made from mahogany and polished to a deep shine\n"+
     "To read the information boards in this study you must enter:\n"+
     "  proread, contranote or levelremove ....\n";
    move_object(
    clone_object("players/llort/arch_guild/proboard"),this_object());
    move_object(
    clone_object("players/llort/arch_guild/conboard"),this_object());
    move_object(
    clone_object("players/llort/arch_guild/lvlboard"),this_object());
tatboard= clone_object("obj/board");
tatboard->set_file("/players/haplo/fun/boards/chatboard");
tatboard->set_name("Ultra Secret Information, and Make fun of Gandalf");
move_object(tatboard, "players/haplo/fun/board");
spherea=clone_object("/players/haplo/misc/orb.c");
sphereb=clone_object("/players/haplo/misc/orb.c");
move_object(spherea, this_object());
move_object(sphereb, this_object());
  }
}

void init() 
{

 if (interactive(this_player()) &&
     member_array(this_player()->query_real_name(),SUPERWIZ)==-1)
 {
      tell_object(this_player(),
      "As you sneakily try to enter Tatsuo's and Haplo's study you are blasted\n\n"+
      "by a powerful BALL OF FIRE!!!!                                   \n\n");
      call_out("not_allowed",1,this_player());
  }

  ::init();
}

void not_allowed(object ob)
{
    if (ob)
    {
    if (ob->query_level() > 29)
        ob->hit_player(ob->query_level());
    tell_object(ob,"You where struck by the law, because of your curiosity !\n");
    ob->move_player("X#room/church");
    shout(capitalize(ob->query_real_name())+" was taken to his death in horrible"+
          ",screaming agony!!\n");
    }
}
      

