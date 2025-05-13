inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("horn");
  set_alias("horn");
  set_short("A black horn");
  set_long("A strange black horn, made by orc hands .\n");
  set_weight(1);
  set_value(50);
}
init(arg) {
  ::init(arg);
  add_action("blow_horn","blow");
  add_action("scare_pl","boe");
}

blow_horn(arg) {
 if (arg == "horn" || arg == "Horn")
  {
   write("You blow the horn and hear: POEEWAAP!\n");
   say(this_player()->query_name()+" blows the horn: POEEWAAP!\n");
   return 1;
  }
}
scare_pl(arg) 
{
object victim;

  if(!arg) return 0;
  victim=present(arg,environment(this_player()));
  if(victim)
   {
   write("You blow the horn right in "+victim->query_name()+"'s face.\n");
    say(this_player()->query_name()+" blows the horn in the middle of "+
        victim->query_name()+"'s face.\n",victim);
    tell_object(victim,this_player()->query_name()+" blows a horn in the "+
                "middle of your face!\n");
    victim->runaway();
   }
  return 1;
}
