inherit "obj/container";
object ob;
reset(arg) {
    ::reset(arg);
    if (!arg) {
        set_weight(100);
      set_max_weight(15);
      set_value(35);
 set_name("skeleton");
        set_long("The skeleton of a one time prisoner, looking rather dead now!\n");
      set_can_close(1);
ob= clone_object("/players/redsexy/jedi/objects/jabba_2");
move_object(ob, this_object());
    }
}
