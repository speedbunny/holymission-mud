inherit "obj/weapon";
reset(arg){
::reset(arg);

set_short("Short Rod");
set_name("Short Rod");
set_alias("rod");
set_long("This is a short, and rather plain looking rod. It is a redish color,\n"+
         "and about as thick as a small branch. It however looks to be very\n"+
         "old. It might be a weapon of some kind, but its so old you guess\n"+
         "that it would not be a very good one.\n");
set_class(4);
set_value(2000);
set_weight(5);
set_hit_func(this_object());
}
int weapon_hit(object victim){
  if(victim->query_race()== "darkfriend"){
     write("A bolt of liquid white fire shoots out of the rod!\n");
     return 400;
}
}
