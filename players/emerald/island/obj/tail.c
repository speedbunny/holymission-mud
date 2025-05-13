inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("tail");
    set_class(12);
    set_weight(2);
    set_value(600);
    set_alias("dragontail");
    set_short("dragontail");
    set_long("The dragontail is covered in sharp scales.  It seems to "+
             "be the perfect weapon for fighting dragons.\n");
     set_hit_func(this_object());
}

int weapon_hit(object ob){
  if (ob->query_race() != "dragon")
    return 0;


    write("Your tail cuts big wounds into the body of the dragon.\n");
    say(this_player()->query_name()+" slams "+
    this_player()->query_possessive()+
   " dragontail deep into "+ob->query_name()+"'s body.\n");
    return(20+random(40));
}
