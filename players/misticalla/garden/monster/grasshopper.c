inherit "obj/monster";
object ob;
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
       set_name("grasshopper");
       set_short("A little green grasshopper");
       set_long("It is looking for some insects and hoping that the evil mouse don't find him.\n");
      load_chat(4,({ "CHIIIRP ...\n" }) );
      set_level(2);
      set_size(1);
      set_al(10);
      set_aggressive(0);
      set_whimpy();
      ob=clone_object("players/misticalla/garden/obj/helmet");
      move_object(ob,this_object());
  }
}
 
 
