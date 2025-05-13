#include "mroom.h" // no ; after #-directives moonie 110893

reset(arg) {

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "Welcome to Middle Earth";
  long_desc =
              "You climb and climb and lose track of time. Suddenly you " +
              "find yourself on solid ground. You see a magnificent " +
              "white tower in the distance to the west and a foreboding " +
              "darkness to the East. You can see jagged mountains and a "+
              "a cloud of black fumes in that direction. To the north " +
              "you see a large green forest.\n";

  dest_dir = ({
    MET+"/tree1", "down",
    SHIRE+"/entrance", "southwest",
  });
}
