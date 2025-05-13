#include "../defs.h"

inherit "obj/monster";

status busy_catching;

void reset( int arg ) {
  ::reset(arg);
  if (arg) return;

  set_name( "mikajel the vampire" );
  set_alias( "mikajel" );
  set_alt_name( "vampire" );
  set_short( "Mikajel the vampire" );
  set_long( "Mikajel does not quite look like the average vampire. He's "
    + "dressed in an old set of sturdy outdoor clothes. His chestnut hair "
    + "looks rather dishevelled. His corner teeth are only slightly longer "
    + "than his other teeth. In his eyes you see anger, disgust, desire and "
    + "enormous self-discipline take turns.\n" );
  set_level( 25 );
  set_race( "undead" );
  set_al( 20 );
  set_ac( 3 );
  set_wc( 12 );
  load_chat( 10, ({
    "Mikajel forces himself to look away from your neck.\n",
    "Mikajel shoots an angry glance in the direction of the black tower.\n",
    "Mikajel shivers with disgust.\n",
    "With a twist of his head, Mikajel stares at your neck.\n",
  }) );
  busy_catching = 0;
}

void init() {
  ::init();
  add_action( "do_give", "give" );
}

void catch_tell( string str ) {
  string tmp1. tmp2;

  if( busy_catching ) return;
  if( query_race() != "undead" ) return;
  busy_catching = 1;
  if( strstr( str, TPRNAME ) != -1 ) {
    tell_room( environment( TO ), 
      "Mikajel says: Well, well... never heard of you before. New on the "
      + "job of vampire hunting, are you?\n" );
    busy_catching = 0;
    return;
  }
  if( sscanf( str, "%shunt%svampire%s", tmp1, tmp2 ) == 2 ||
      sscanf( str, "%svampire%shunt%s", tmp1, tmp2 ) == 2 ) {
    tell_room( environment( TO ),
      "Mikajel says: You'll probably not believe it, but I used to be a "
      + "vampire hunter before Fate turned against me and made me into "
      + "what I am now. I could tell you more about the history of these "
      + "lands, if you want, or I can give you some hints about how the "
      + "curse may be lifted. You might need it if you want to survive.n\" );
    busy_catching = 0;
    return;
  }
  if( sscanf( str, "%shistory%s", tmp1, tmp2 ) == 2 ) {
    tell_room( environment( TO ),
      "Mikajel says: In the old days, this used to be a fertile county. "
      + "Until the days of Lord Sashya, a crazy noble, mortally afraid of "
      + "dying and willing to sacrifice anything to avoid death. He hired "
      + "an evil mage to help him achieve his goal. And one bad day, the "
      + "sky turned black in the middle of the day lightning struck the "
      + "Lord's tower thirteen times. From the following night people "
      + "started to be missing. Strange things appeared in the tower, which "
      + "was now closed for anyone. The local priests were furious at the "
      + "obviously satanic rituals being carried out at the tower. They "
      + "organised a raid and in the attack the lord was killed. They "
      + "thought. Thirteen nights after his burial he reappeared and took "
      + "revenge on the priests. In dying they prayed their gods to curse "
      + "these lands, and so it has been up to this day...\n" );
    busy_catching = 0;
    return;
  }
  if( sscanf( "%shint%s", tmp1 ) == 1 ) {
    tell_room( environment( TO ),
      "Mikajel says: When I searched to destroy the evil count, I ran into "
      + "an ambush and they punished me by making them on of their own. "
      + "But I won't allow myself to become a monster! If you wish to "
      + "share in my knowledge, you must help me keep my burden bearable "
      + "by ...\n" );
    busy_catching = 0;
    return;
  }
}

int do_give( string str ) {
  string what, whom;
  object cross;

  if( !str ) return;
  if( sscanf( str, "%s to %s", what, whom ) != 2 ) {
    notify_fail( "Give what to whom?\n" );
    return 0;
  }
  if( !id( whom ) ) return 0;
  if( what != "cross" && what != "silver cross" ) {
    notify_fail( "Mikajel refuses to accept that gift.\n" );
    return 0;
  }
  if( !( cross = present( "silver cross", this_player() ) ) ) {
    notify_fail( "You don't possess such a silver treasure.\n" );
    return 0;
  }
  if( (int)cross->query_drain_level() < 3 ) {
    notify_fail( "Mikajel sighs.\nMikajel says: I had hoped you would "
      + "have been able to charge such a cross with enough power to lift "
      + "my curse.\n" );
    return 0;
  }
  set_name( "mikajel the baby" );
  set_alias( "mikajel" );
  set_alt_name( "baby" );
  set_short( "Mikajel the baby" );
  set_long( "Mikajel looks like a healthy human baby. Rozy cheeks, some "
    + "wild tuffs of chestnut hair and very big blue eyes that seem to "
    + "hide some deep wisdom. He smiles all the time.\n" );
  set_level( 1 );
  set_race( "human" );
  set_al( 100 );
  set_ac( 1 );
  set_wc( 1 );
  load_chat( 10, ({
    "Mikajel says: Da da da da.\n",
    "Mikajel smiles happily.\n",
    "Mikajel says: Eeeeeh! Ga ga.\n",
  }) );
  call_out( "take_him_home", 600 );
  this_player()->add_exp( 5000 );
  printf( "You give the silver cross to Mikajel.\nMikajel smiles like a "
    + "child on its birthday. He takes the cross and puts it on a big "
    + "stone he uses as an altar. Then he says a short prayer. A single "
    + "bright ray of sun suddenly shines through the roof, setting "
    + "Mikajel in afire with silver flames.\nMikajel says: Finally I may "
    + "be reborn as a proper human. Thank you, %s!\n",
    this_player()->query_short_name() );
  say( sprintf( "%s gives a silver cross to Mikajel.\nSuddenly a single "
    + "ray of sun light sets Mikajel afire with silver flames.\nMikajel "
    + "says: Finally I may be reborn as a proper human. Thank you %s!\n",
    this_player()->query_name(), this_player()->query_short_name() ),
    this_player() );
  return 1;
}

void take_him_home() {
  if( living( environment() ) ) {
    tell_room( environment( environment() ) ),
      sprintf( "A stork descends from the air and lands on %s's shoulder.\n",
        environment()->query_name() ) );
    tell_object( environment(),
      "Stork whispers in your ear: Sorry, but I really have to take "
      + "baby Mikajel to his new parents now. Thank you for taking care "
      + "of him in the meantime.\nThe stork wraps baby Mikajel in a sling "
      + "in his bill.\n" );
    tell_room( environment( environment() ),
      + "A stork takes off into the sky again.\n" );
  }
  else tell_room( environment(),
    "A stork descends from the sky and lands next to baby Mikajel. "
    + "Carefully the stork wraps baby Mikajel in a sling. The stork takes "
    + "the sling in his bill and takes of into the sky again.\n" );
  destruct( this_object() );
}


