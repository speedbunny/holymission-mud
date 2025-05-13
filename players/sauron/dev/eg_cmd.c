// Makes it more difficult to detect tracks
#include <std.h>
#include <daemons.h>
inherit DAEMON;

int cmd_hide(string str){
  int skill, i;
  mixed *tracks;

  if (str != "tracks") return 0;
  if (!SPELL_D->base_check(this_player())) return 0;
  if (this_player()->query_sp()<10)
    return notify_fail("You're to tired to hide any tracks.");
  skill = this_player()->query_skill("forestry");
  skill += this_player()->query_stats("intelligence")/3;
  skill += this_player()->query_stats("perception")/3;
  skill += random(this_player()->query_stats("luck"));
  if (this_player()->is_class("ranger"))
    skill += this_player()->query_level()/2;.
  if
(member_array(this_player()->query_race(),({"elf","halfling","sidhe","centaur"})
)!=-1)
    skill += this_player()->query_level()/8;
  skill = skill/3 + random(skill*2/3);
  write("You do your best to hide any tracks in the area.");
  say(this_player()->query_cap_name()+" carefully hides hides any tracks in the
area.");
  tracks = environment(this_player())->query_tracks();
  for (i=0;i<sizeof(tracks);i++){
    tracks[i][3] += skill/2+random(skill/2);
    this_player()->add_sp(-2);
    this_player()->add_skill_points("forestry",skill/10);
  }
  environment(this_player())->set_all_tracks(tracks);
  this_player()->set_paralyzed(i+random(i), "You are busy hiding the tracks.");
  return 1;
}
