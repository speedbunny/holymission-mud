id( str )
{
   return( str == "bone key" || str == "key" || str == "_bone_key_" );
}

query_name()
{
   return( "bone key" );
}

short()
{
   return( "A bone key" );
}

long()
{
   write( "A key, cut out of a bone.\n" );
}

get()
{
   return( 1 );
}
