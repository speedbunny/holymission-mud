#define SPELL     "/players/redsexy/guild/spell/"

int query_delay() {
  return 1;
}

int main(string strArgs) {

  int     i, j;
  string  *spellname;
  string  strNewArgs;

  if(!strArgs || strArgs == "") {
    write("You must supply an element to call!\n");
    return 1;
  }
  spellname = explode(strArgs, " ");
  i         = sizeof(spellname);
  if(i > 1) {
    for(j = 1; j < i; j++) {
      if(j == 1) {
        strNewArgs = spellname[j];
      }
      else {
        strNewArgs = strNewArgs + " " + spellname[j];
      }
    }
  }
  if(spellname[0][0] == 39 || spellname[0][0] == 46)
    return 0;

  if(spellname[0][strlen(spellname[0])-1] == '.')
    return 0;

  if(file_size(SPELL + spellname[0] + ".c") > 0) {
//    write("Calling " + spellname[0] + " with args " + strNewArgs + ".\n");
    return (SPELL + spellname[0])->main(strNewArgs);
  }

  notify_fail("That is not a valid elemental spell.\n");
  return 0;
}
