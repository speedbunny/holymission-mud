/* Changed by Ethereal Cashimor: bed removed */
/* 260393 Cashimor: key repaired. */
inherit "room/room";
object key;
 
#define LOBBY "players/animal/closed/lobby"
 
int room_no;
object thisplace;
object clock,chair1,bed;
string own;
 
realm() { return "NT"; }
query_own() { return own; }
query_cabin() { return 1; }
 
init() 
{
::init();
 
  add_action("bring_player","bring");
  add_action("emote","emote");
  add_action("emote");  add_xverb(":");
 
  if(!clock)
    {
      clock=clone_object("players/animal/obj/timer");
      transfer(clock,thisplace);
      clock->set_room_no(room_no);
      chair1=clone_object("players/animal/obj/recliner");
      transfer(chair1,thisplace);
     bed=clone_object("players/cashimor/things/bed");
      move_object(bed,thisplace);
    }
}
 
bed() {
/*
  if(capitalize(this_player()->query_real_name())!=own)
    {
      write("You may not buy a bed, this is not yer cabin!\n");
      return 1;
    }
*/
 
     if(this_player()->query_money() < 500) {
     write("Not enough cash chump!!\n");
     return 1;
     }
     if(present("bed",thisplace)) {
     write("There is a bed here already!!\n");    
     return 1;
     }
     this_player()->add_money(-500);
     write("Your bed magically arrives.\n");
     write("Look at it.\n"); 
      bed=clone_object("players/animal/obj/bed");
      transfer(bed,thisplace);
      bed->set_room_no(room_no);
      return 1; 
}
 
emote(str)  {
     say(this_player()->query_name()+" "+str+"\n");
     write("You emote: "+str+"\n");
     return 1;
}
 
reset(arg) 
{
::reset();
  if(arg) return;
  
  set_light(1);
  dest_dir = 
    ({
      LOBBY,"out"
      });
}
 
clean_up()
{
	if(clock)
  destruct(clock);
	if(chair1) {
  chair1->exit(chair1->query_sitter());
  destruct(chair1);
	}
if(bed)
  destruct(bed);
if(key)
	if(find_player(lower_case(own)))
	{
	key->kill(find_player(lower_case(own)));
	}
	else destruct(key);
}
 
bring_player(who)
{
  string inv;
  object player;
  
  inv=LOBBY->query_bring(room_no);
  own=LOBBY->query_renter(room_no);
 
  if(capitalize(this_player()->query_real_name())!=own)
    {
      write("You may not bring others here, this is not yer cabin!\n");
      return 1;
    }
 
  if(inv)
    {
      player=find_living(lower_case(inv));
      write("You were bringing "+inv);
      if(player)
{
  write(".\n");
  tell_object(player,own+" no longer wants you to come to the cabin.\n");
}
      else
write(" (not in the game anymore).\n");
      LOBBY->set_bring(0,room_no);
    }
  else
    write("You are not bringing anyone currently.\n");
 
  if(who)
    {
      player=find_living(lower_case(who));
      if(!player)
          write("No player with that name.\n");
      else
{
  who=capitalize(who);
  tell_object(player,own+" wants you to come to a PARTY! Condo #"+room_no+".\n");
  tell_object(player,"If ya don't know where its at, ask around!\n");
  LOBBY->set_bring(who,room_no);
  write(who+" was told to come to your cabin.\n");
}
    }
  return 1;
}
 
exit(ob)
{
object key1;

	if(!living(ob)) return 0;
  own=LOBBY->query_renter(room_no);
 
if(key1 = present("cabin key",this_player())) {
if(key1->query_number() == room_no) destruct(key1);
}
 
   if(this_player() && capitalize(this_player()->query_real_name()) == own) {
 
  key = clone_object("players/animal/obj/key");
  key->set_own_name();
  move_object(key,this_player());
  key->set_value(current_value());
  key->set_number(room_no);
   }
  if(chair1)
    chair1->exit(ob);
  return 0;
}
 
current_value() {
  object ob,next;
  int value;
int vl;
 
  ob=first_inventory(this_object());
  value=0;
  while(ob)
    {
      next=next_inventory(ob);
      if(living(ob))
{
ob = next;
        continue;
}
      else
     if(ob->query_value())
	{
	if(ob->query_value() > 1200) vl = random(300) + 500;
    if(ob->query_value() > 10000) vl = random(500) + 500;
	else vl = ob->query_value();
      value = value + vl;
	}
     ob=next;
    }
  return value;
}
