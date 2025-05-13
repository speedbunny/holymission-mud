/* Help function for Controller devices */

help(str)
{
  if(!str)
   return;
  switch(str)
  {
    case "clouds":
         write(" <<>>                                      <<>>\n"+
               "  Cloud City Cloud Control Wand Help Menu\n\n"+
               "  1) What is a Cloud Control Wand\n"+
               "  2) What does access mean\n"+
               "  3) What does density mean\n"+
               "  4) How to upgrade your wand\n"+
               "  5) Basic commands while in the CCCS\n"+
               "\n  help clouds <number>\n"+
               " <<>>                                      <<>>\n");
         return 1;
         break;
    case "clouds 1":
         write("Ix is famous for its machine culture and your control\n"+
               "device is no exception. The Ixian Cell Control device\n"+
               "allows access to the Ixian Cellular Transportation System.\n"+
               "Only certain places/rooms have access to the ICTS, so\n"+
               "access is limited. The ICTS also has interplantary access\n"+
               "unknown to the Spacing Guild. Owning a ICC means you are\n"+
               "part of the secret Ixian MAchine Guild.\n");
         return 1;
         break;
    case "clouds 2":
         write("Access determines your ability to do and see things in\n"+
               "any particular cell. For example, if you search a cell\n"+
               "and find nothing, that could be true or maybe you just\n"+
               "need to upgrade your CCCS wand.\n");
         return 1;
         break;
    case "clouds 3":
         write("Density of your Cloud Control wand determines\n"+
               "how deep you can get in the CCCS. The deeper you go into\n"+
               "the CCCS the more you will need to find/buy upgrades.\n");
         return 1;
         break;
    case "clouds 4":
         write("Upgrading your wand by finding/buying upgrades. These\n"+
               "objects are used to upgrade wand's so the user of the CCCS\n"+
               "can get to cells with a higher access. There are 3 known\n"+
               "types of upgrades, but there are bootleg upgrades which\n"+
               "which could distroy your wand.\n");
         return 1;
         break;
    case "clouds 5":
         write("Several commands apply to apply this wand:\n\n"+
               "help clouds           Help display\n"+
               "enter clouds          Accesses the CCCS\n"+
               "enter                 Displays enterable cells\n"+
               "enter <cell>          Accesses given <cell>\n"+
               "insert                Inserts a upgrade \n"+
               "search <where>        Searchs <where> in CCCS\n"+
               "\n\n <<>>                                       <<>>\n");
         return 1;
         break;
    default:
         return;
  }
}
