inherit "obj/treasure";

void reset(int arg)
  {if(arg)
    return;
  set_id("skid");
  set_alias("marks");
  set_weight(2000);
  set_value(1);
  set_short("A skidmark");
  set_long("A set of skidmarks left by a wheelchair.\n"+
  "These old fogies really know how to have fun.\n"+
  "You can only hope you can grow old enough to\n"+
  "a wheelchair like they can!\n");}
