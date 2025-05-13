#ifndef __P_GROUP_C__

#define __P_GROUP_C__

#include "player_defs.h"
#include "player_group.h"

nomask int query_grouped() {
  return grouped;
}

/*--------------------------------------------------------------------------*/
/* Are we the member of a party? and who all is in the romo with us?        */
/*--------------------------------------------------------------------------*/
nomask int query_party_member(object ob) {
  if(!grouped)
    return 0;
  if(follow_whom)
    return((ob==follow_whom && ob->query_grouped()) ||
            member_array(ob, follow_whom->query_followers())!=-1);
  else
    return(follow_obj && member_array(ob, follow_obj)!=-1);
}

mixed grmems_in_room() {
  object *mems, *folls;
  int    i, sz;

  if(grouped) {
    mems = ({});
    if(!follow_whom) {     /* we are the leader */
      mems += ({ TO });
      folls = query_followers();
    }
    else {
      if(follow_whom->query_grouped() &&  ENV(follow_whom)==ENV())
        mems += ({ follow_whom });
      folls = follow_whom->query_followers();
    }
    if(folls)
      for(sz=sizeof(folls), i=0; i<sz; i++)
        if(folls[i]->query_grouped() && ENV(folls[i]) == ENV())
          mems += ({ folls[i] });
  }
  else
    mems = ({ TO });
  return mems;
}

void toggle_grouped() {
  grouped = !grouped;
  if(grouped)
    tell_room(ENV(TP), TO->NAME + " has been grouped.\n");
  else
    tell_room(ENV(TP), TO->NAME + " has been kicked out of the group.\n");
  return;
}


#endif // __P_GROUP_C__
