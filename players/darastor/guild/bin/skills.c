/* command:     skills
 * syntax:      skills
 * function:    list barbarian skills
 */

#include <lw.h>

string wrap(int i) {
    switch(i) {
      case 100:  return "" + i;   break;
      case 0..9: return ".." + i; break;
      default:   return "." + i;  break;
    }
}

int main() {
  printf( "Combat....... %s [100]\n"
    + "Melee........ %s [100]\n"
    + "Toughness.... %s [100]\n"
    + "Fortitude.... %s [100]\n"
    + "Speed........ %s [100]\n",
    wrap( (int)this_player()->get_skill( "barbarian_combat" )[0] ),
    wrap( (int)this_player()->get_skill( "barbarian_melee" )[0] ),
    wrap( (int)this_player()->get_skill( "barb_toughness" )[0] ),
    wrap( (int)this_player()->get_skill( "barbarian_fortitude" )[0] ),
    wrap( (int)this_player()->get_skill( "barbarian_speed" )[0] ) );
  return 1;
}
