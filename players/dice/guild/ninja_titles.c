get_pretitle( level )
{
   switch( level ) {
      case 1..10:  return( "Genin" );
      case 11:  return( "Executioner" );
      case 12:  return( "Executioner" );
      case 13:  return( "Executioner" );
      case 14:  return( "Assassin" );
      case 15:  return( "Assassin" );
      case 16: return( "Assassin" );
      case 17: return( "Chunin" );
      case 18: return( "Chunin" );
      case 19: return( "Chunin" );
      case 20: return( "Master" );
      case 21: return( "Master" );
      case 22: return( "Master" );
      case 23: return( "Ninja" );
      case 24: return( "Ninja" );
      case 25: return( "Ninja" );
      case 26: return( "Ninja" );
      case 27: return( "Jonin" );
      case 28: return( "Jonin" );
      case 29: return( "Sensei" );
      default: break;
   } 
   
     if(this_player()->query_gender()==1) return("Lin Kuei Master");
   if(this_player()->query_gender()==2) return ("Lin Kuei Mistress");
}

get_skill_title( level )
{
   int    mainLevel, subLevel;
   string ret;
   
   mainLevel = (level-1) / 9;
   if ( mainLevel == 11 )
      return( "grandmaster" );

   subLevel = (level-1) % 9;

   switch( subLevel ) {
      case 0:  ret = "novice "; break;
      case 1:  ret = "apprentice "; break;
      case 2:  ret = ""; break;
      case 3:  ret = "confident "; break;
      case 4:  ret = "seasoned "; break;
      case 5:  ret = "expert "; break;
      case 6:  ret = "eminent "; break;
      case 7:  ret = "brilliant "; break;
      case 8:  ret = "superior "; break;
      default: ret = "";
   } 
   switch( mainLevel ) {
      case 0:  ret += "beginner"; break;
      case 1:  ret += "student"; break;
      case 2:  ret += "amateur"; break;
      case 3:  ret += "layman"; break;
      case 4:  ret += "acolyte"; break;
      case 5:  ret += "journeyman"; break;
      case 6:  ret += "craftsman"; break;
      case 7:  ret += "professional"; break;
      case 8:  ret += "veteran"; break;
      case 9:  ret += "master"; break;
      case 10: ret += "teacher"; break;
      default: ret += "";
   }

   return( ret );
}
