Int_t runFileStagerTest()
{
  TString server("root://valtical08.cern.ch/");
  TString dir( server + "/localdisk/xrootd/test/" );
  TString file1( dir + "test1.root" );
  TString file2( dir + "periodH1.root" );
  TString file3( dir + "periodH4.root" );

  TFileStager *s  = TFileStager::Open( server );

  // IsStaged()
  Bool_t isStaged = s->IsStaged( dir + "nonexisting.root" );
  std::cout << "File is staged: " << ( isStaged ? "true" : "false" ) << std::endl;
  Bool_t isStaged = s->IsStaged( file1 );
  std::cout << "File is staged: " << ( isStaged ? "true" : "false" ) << std::endl;

  // Locate()
  TString endpoint = 0;
  if( s->Locate( file1, endpoint ) != 0 )
  {
    std::cout << "Error locating file" << std::endl;
    return 1;
  }
  std::cout << "Endpoint: " << endpoint << std::endl;

  // LocateCollection()
  TFileCollection *fc = new TFileCollection();
  fc->Add( new TFileInfo( file1 ) );
  fc->Add( new TFileInfo( file2 ) );
  fc->Add( new TFileInfo( file3 ) );
  s->LocateCollection( fc );

  // Stage() single
  if( s->Stage( file1 ) != 0 )
  {
    std::cout << "Error staging single" << std::endl;
    return 1;
  }

  // Stage() multiple
  TList t = TList();
  t.Add( (TObject*) TUrl( file1 ) );
  t.Add( (TObject*) TUrl( file2 ) );
  t.Add( (TObject*) TUrl( file3 ) );
  if( s->Stage( (TCollection*) t, "priority=1" ) != 0 )
  {
    std::cout << "Error staging multiple" << std::endl;
    return 1;
  }
  return 0;
}

