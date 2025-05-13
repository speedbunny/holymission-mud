inherit "obj/weapon";
  reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("starsword");
  set_alias("sword");
  set_value(2000);
   set_class(10);
  set_hit_func(this_object());
  set_weight(2);
  set_short("The Starsword");

  set_long("This ancient sword is said to have special powers "+
 "which depend on the wielder.\n");
}
int weapon_hit(object mob){
 string tpg;
  string tpn;
tpg = ("/guild/master"->query_name(this_player()->query_guild()));
tpn = this_player()->query_name();




if(random(100)<30) {
if(tpg=="fighter") {
  say("The Starsword uses "+tpn+"'s prowess as a "+
  "Fighter to inflict heavy damage!\n");
 write("The Starsword uses "+tpn+"'s prowess as a Fighter "+
"to inflict heavy damage!\n");
  return 30;
}


if(tpg=="mage") {
 say("The Starsword channels a blast of power from "+
 tpn+"'s magical abilities!\n");
 write("The Starsword channels a blast of power from "+
 tpn+"'s magical abilities!\n");
 return 30;

}
if(tpg=="thief") {
say("The Starsword guides "+
tpn+"'s dexterous skill to inflict damage!\n");
write("The Starsword guides "+
tpn+"'s dexterous skill to inflict damage!\n");
return 30;
}


if(tpg=="ninja") {
say("The Starsword uses "+
tpn+"'s deadly abilities to inflict damage!\n");
write("The Starsword uses "+
tpn+"'s deadly abilities to inflict damage!\n");
return 30;
}


if(tpg=="monk") {
say("The Starsword draws on "+
tpn+"'s inner focus to seek a vital strike!\n");
write("The Starsword draws on "+
tpn+"'s inner focus to seek a vital strike!\n");
return 30;
}



if(tpg=="vagabond") {
say("The Starsword channels "+
tpn+"'s powers of time and space!\n");
write("The Starsword channels "+
tpn+"'s powers of time and space!\n");
return 30;
}



if(tpg=="barbarian") {
say("The Starsword calls upon "+
tpn+"'s mighty strength!\n");
write("The Starsword calls upon "+
tpn+"'s mighty strength!\n");
return 30;
}



if(tpg=="bard") {
say("The Starsword performs a deadly dance in the hands of "+
tpn+"!\n");
write("The Starsword performs a deadly dance in the hands of "+
tpn+"!\n");
return 30;
}



if(tpg=="jedi") {
say("The Starsword feels the Force within "+
tpn+" and strikes hard!\n");
write("The Starsword feels the Force within "+
tpn+" and strikes hard!\n");
return 30;
}


if(tpg=="adventurer") {
say("The Starsword is filled with "+
tpn+"'s adventuring spirit!\n");
write("The Starsword is filled with "+
tpn+"'s adventuring spirit!\n");
return 30;
}





/*end if*/
}
/*end weapon_hit*/
return 0;
}
