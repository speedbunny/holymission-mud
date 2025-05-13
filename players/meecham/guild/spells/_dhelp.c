#define HLP "/players/meecham/guild/helpdir/"
#define TP this_player()
#define GM "guild/master"

status do_spell(string str) {
  string *name;
  int i,j;
  string file;

  file = "_";
  if(str) {
    if(str == "levels") {
      GM->list_levels(2,TP->query_gender());
      return 1;
    }
    if(str == "legendlevels") {
      GM->list_legend_levels(2,TP->query_gender());
      return 1;
    }
    name = explode(str, " ");
  }
  else {
    write("You must choose a category of help.\n");
    write("These will be posted later.\n");
    return 1;
  }
  i = sizeof(name);
  if (i > 1) {
    for (j = 0;j < i;j++)
      if (j == i - 1)
        file += name[j];
      else
        file += name[j] + "_";
  } else 
    file += str;
  file = HLP + file + ".txt";
  if (file_size(file) != -1)
    cat(file);
  else 
    printf("Sorry, no guild help file for %s.\n" +
           "If you feel there should be one, mail Meecham.\n", str);
  return (1);
}
