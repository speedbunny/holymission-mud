/* A sign to point the way to my place */

id(str)
{
  return str == "sign";
}

short()
{
  return "A sign";
}

long()
{
  write("To the north is the Castle of Kbl. Doesn't look like there's much\n"+
        "around there, but you have to search everywhere... Nasty tough\n"+
        "creatures there and some nice items. Good luck!!!\n");
}

get()
{
  return 0;
}

