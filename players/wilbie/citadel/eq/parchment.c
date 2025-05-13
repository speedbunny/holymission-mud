inherit "/obj/treasure";
reset(arg){
  if (arg)return;
  set_id("parchment");
  set_short("A bloody parchment");
  set_long("The bloody parchment reads:  'I have found the truth of "+
"Sheankala!  She is merely a guardian to some greater power, of what name "+
"I do not yet know.  I have found evidence in the texts, and a way to "+
"get to the realm of this powerful being who even Sheankala fears."+
"\n"+
"\n"+
"One must hold a shattered bone fragment at the circle of power, and then "+
"simply kneel.  There are fragments to be found at the entrance to the "+
"dungeons."+
"\n"+
"\n"+
"I fear that the Matriarch shall have me put to death.  She considers what "+
"I know to be heresy!  But I shall prove her wrong...  I shall awaken the "+
"true Dark One myself!"+
"\n");
  set_value(2);
  set_weight(1);
}
