void reset( int tick )
{
   call_out( "dest_me", 10 );
}

dest_me()
{
   destruct( this_object() );
}

#if 0
CAUSED BAD EWOULDBLOCKS !!! (patience)
object victim,shadow;
int age;
string *vic_messages=({
	"You cough violently.\n",
	"You feel about to puke.\n",
	"You feel very ill.\n",
	});
string *other_messages=({
	" coughs violently.\n",
	" looks about to puke.\n",
	" looks ill.\n",
	});

drop() {
  return 1;
}

id(str) {
  return str=="Disease";
}

start() {
  victim=environment();
  set_heart_beat(1);
}

heart_beat() {
  age++;
  if(age==30) {
    shadow=clone_object("players/moonchild/cave/d_shadow");
    shadow->start_shadow(victim);
    message();
  }
  else if(age==120) {
    destruct(shadow);
    tell_object(victim, "You feel better now.\n");
  }
  else if(age>100 && !random(6))
    message();
} 

message() {
  int i;
  i=random(3);
  move_object(this_object(), environment(victim));
  tell_object(victim, vic_messages[i]);
  say(victim->query_name() + other_messages[i], victim);
  victim->reduce_hit_point(2+random(3));
  move_object(this_object(), victim);
}
#endif
