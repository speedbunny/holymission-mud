#define TP this_player()

help(arg,string GM,int gd) {
   string skills;
  switch(arg) {
    case "guild":
      TP->more ("/players/portil/guild/docs/fhelp.txt");
      break;
    case "levels":
      GM->list_levels(gd);
      break;
    case "skills":
      skills = call_other("/players/portil/guild/room","list_skills",TP,1);
      write(skills);
      break;
    case "spell":
    case "spells":
      write("Fighters are not able to use spells.\n");
      break;
    case "check":
      cat ("/players/portil/guild/docs/check");
      break;
    case "parry":
      cat("/players/portil/guild/docs/parry");
      break;
    case "fix":
      cat("/players/portil/guild/docs/fix");
     break;
    case "but":
      cat ("/players/portil/guild/docs/but");
      break;
    case "breadcrumbs":
      cat ("/players/portil/guild/docs/breadcrumbs");
      break;
    case "munch":
      cat ("/players/portil/guild/docs/munch");
      break;
    case "stronghold":
      cat ("/players/portil/guild/docs/stronghold");
      break;
    case "compare":
      cat ("/players/portil/guild/docs/compare");
      break;
    case "track":
       cat("/players/portil/guild/docs/track");
       break;
    case "berzerk":
      cat ("/players/portil/guild/docs/berzerk");
      break;
    case "fighter":
    case "fighters":
      cat ("/players/portil/guild/docs/fighter");
      break;
    case "legends":
      cat ("/players/portil/guild/docs/legends");
    break;
    case "rescue":
      cat ("/players/portil/guild/docs/rescue");
      break;
    case "fshout":
      cat("/players/portil/guild/docs/fshout");
      break;
    case "bash":
      cat ("/players/portil/guild/docs/bash");
      break;
    case "lower":
      cat ("/players/portil/guild/docs/lower");
      break;
    case "block":
      cat ("/players/portil/guild/docs/block");
      break;
    case "calm":
      cat ("/players/portil/guild/docs/calm");
      break;
    case "weaponskills":
      cat("/players/portil/guild/docs/weaponskills");
    break;
    case "skillstats":
       cat("/players/portil/guild/docs/skillstats");
    break;
    case "query time":
      cat ("/players/portil/guild/docs/query_time");
      break;
    default:
      notify_fail("Help with what?\n");
      return 0;
  }
  return 1;
}
