/*-------------------------------------------------------------------------*/
/* FILE : help.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              get help on a variety of topics.                           */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  string dummy;
  string keyword, help_file;
  mixed *spell_dat, *soc;
  int   i, max;

  notify_fail("No help available!\n");

  if(!str) {
    cat("/doc/help");
    return 1;
  }

  switch(str) {
    case "levels" :
      if(guild)
        return 0;
      break;
    case "wiz" :
    case "wizard" :
      if(TP->IMM) {
        cat("/doc/wiz_help");
        return 1;
      }
      break;
    case "testplayer" :
      if(TP->IMM) {
        cat("/doc/testplayer");
        return 1;
      }
      break;
  }

  str = do_fit(({ "wizard", "testplayer", "expander", "quicktyper" }), str);

  if(str) {
    if(sscanf(str, "%s..%s", dummy) == 1)
      return 0;
    /* Herp: maybe there's help available in the guild file. */
    str = do_fit(get_dir("/doc/helpdir/*"), str); /**/
    write("Help on " + str + ":\n");

    if(sizeof(explode(str," ")) > 1 || !cat("/doc/helpdir/" + str)
                                      && guild) ;
    else
      return 1;
  }

  if(str == "social" || str == "socials") {
#if NEW_FEELINGS
    cat(FEELINGS+"social_help");
#else
    SOCIAL_MASTER->show_feelings();
#endif
    return 1;
  }
  if(str == "adverb" || str == "adverbs") {
#if NEW_FEELINGS
    cat(FEELINGS+"adverb_help");
#else
    SOCIAL_MASTER->show_adverbs();
#endif
    return 1;
  }
  if(str == "expander" || str == "quicktyper")
    return help_expander();
// will this be in there?
  if(sscanf(str, "%s %s", keyword, str) == 2) {
    keyword = lower_case(keyword);
    switch(keyword) {
      case "spell":
        dummy = SPELL_MASTER->get_spell(str);
        if(dummy)
          write(dummy->spell_help());
        else
          write("There is no such spell.\n");
        return 1;
      case "ability":
        dummy = ABILITY_MASTER->get_ability(str);
        if(dummy)
          write(dummy->ability_help());
        else
          write("There is no such special ability.\n");
        return 1;
    }
  }
  return 0;
}

