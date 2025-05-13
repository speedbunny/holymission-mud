inherit "/obj/std_shadow";

#include "/players/tamina/defs.h"

int query_arm_light()
{
  return 3;
}

int light_ring_shad()
{
  return 1;
}

object light_ring_object()
{
  return TO;
}

void end_shadow(object obj)
{
  tell_object(me, "The glow around the Ring of Light fades.\n");
  ::end_shadow(obj);
}
