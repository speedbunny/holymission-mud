inherit "/obj/treasure.c";

void reset(int i)
{
  ::reset(i);
  if (i) return;
  set_name("altar");
  set_value(0);
  set_alias("goldsun_quest_altar_for_white_tower");
  set_short("A golden altar");
  set_long("An altar with holy signs engraved on it. You see a siluete of\n"+
          "white tower on it.\n") ;
  set_weight(3);
}

query_quest_item(){  return 1; }   
