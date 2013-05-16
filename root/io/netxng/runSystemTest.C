Int_t runSystemTest()
{
  TString server("root://valtical08.cern.ch/");
  TString dir( server + "/localdisk/xrootd/test/" );
  TString file( dir + "test1.root" );

  // OpenDirectory()
  TSystem *system = new TNetXNGSystem( server );
  void *dirp = system->OpenDirectory( dir );

  // GetPathInfo()
  FileStat_t st;
  system->GetPathInfo( file, st );
  std::cout << "File size: " << st.fSize << std::endl;

  // MakeDirectory()
  if( !system->MakeDirectory( dir + "testdir/" ) == 0 )
  {
    std::cout << "Error making directory" << std::endl;
    return 1;
  }

  // GetDirEntry()
  const char *filename;
  Int_t nfiles = 0;
  while( ( filename = system->GetDirEntry( dirp ) ) != 0 )
    nfiles++;

  if( nfiles == 0 ) return 1;

  // Unlink()
  if( !system->Unlink( dir + "testdir/" ) == 0 )
  {
    std::cout << "Error removing directory" << std::endl;
    return 1;
  }

  // FreeDirectory()
  system->FreeDirectory( dirp );
  return 0;
}
