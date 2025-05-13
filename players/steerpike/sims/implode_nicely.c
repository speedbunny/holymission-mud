string implode_nicely(string *str)
{
   switch (sizeof(str))
   {
      case 0:
	 return "";
      case 1:
	 return str[0];
      case 2:
	 return sprintf("%s and %s", str[0], str[1]);
      default:
	 return sprintf("%s and %s", implode(str[0..<2], ", "), str[<1]);
   }
}
