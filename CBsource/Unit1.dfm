object MainForm: TMainForm
  Left = 313
  Top = 122
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1047#1074#1086#1085#1086#1082
  ClientHeight = 527
  ClientWidth = 691
  Color = clAqua
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clGray
  Font.Height = -12
  Font.Name = 'Arial'
  Font.Style = [fsBold]
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 691
    Height = 506
    ActivePage = SetupWin
    Align = alClient
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clGray
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    MultiLine = True
    ParentFont = False
    TabIndex = 2
    TabOrder = 0
    TabPosition = tpBottom
    object SchedWin: TTabSheet
      Caption = #1056#1072#1089#1087#1080#1089#1072#1085#1080#1077
      object TopPanel: TPanel
        Left = 0
        Top = 0
        Width = 683
        Height = 81
        Align = alTop
        Color = clAqua
        TabOrder = 0
        object ButShowToday: TSpeedButton
          Left = 134
          Top = 40
          Width = 123
          Height = 33
          Hint = #1055#1088#1086#1089#1084#1086#1090#1088' '#1089#1086#1073#1099#1090#1080#1081' '#1085#1072' '#1089#1077#1075#1086#1076#1085#1103
          Caption = 'C'#1077#1075#1086#1076#1085#1103
          Flat = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          OnClick = ButShowTodayClick
        end
        object ButAllEvent: TSpeedButton
          Left = 136
          Top = 2
          Width = 121
          Height = 33
          Hint = #1055#1088#1086#1089#1084#1086#1090#1088' '#1074#1089#1077#1093' '#1089#1086#1093#1088#1072#1085#1077#1085#1085#1099#1093' '#1089#1086#1073#1099#1090#1080#1081
          Caption = #1042#1089#1077' '#1089#1086#1073#1099#1090#1080#1103
          Flat = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clSilver
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          OnClick = ButAllEventClick
        end
        object ButPrevDay: TSpeedButton
          Left = 16
          Top = 24
          Width = 103
          Height = 33
          Hint = #1055#1088#1086#1089#1084#1086#1090#1088' '#1089#1086#1073#1099#1090#1080#1081' '#1085#1072' '#1089#1077#1075#1086#1076#1085#1103
          Caption = #1042#1095#1077#1088#1072
          Flat = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clSilver
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          OnClick = ButShowTodayClick
        end
        object ButNextDay: TSpeedButton
          Left = 278
          Top = 24
          Width = 99
          Height = 33
          Hint = #1055#1088#1086#1089#1084#1086#1090#1088' '#1089#1086#1073#1099#1090#1080#1081' '#1085#1072' '#1089#1077#1075#1086#1076#1085#1103
          Caption = #1047#1072#1074#1090#1088#1072
          Flat = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clSilver
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          OnClick = ButShowTodayClick
        end
        object TabloTime: TLabel
          Left = 493
          Top = 5
          Width = 64
          Height = 23
          Alignment = taCenter
          Caption = '00:00'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGray
          Font.Height = -19
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object TabloDate: TLabel
          Left = 416
          Top = 33
          Width = 224
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Caption = '31 '#1089#1077#1085#1090#1103#1073#1088#1103' 2022 '#1074#1086#1089#1082#1088#1077#1089#1077#1085#1100#1077
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
      object BottomPanel: TPanel
        Left = 0
        Top = 387
        Width = 683
        Height = 90
        Align = alBottom
        Caption = 'BottomPanel'
        Color = clCream
        TabOrder = 1
        object PageControl2: TPageControl
          Left = 1
          Top = 1
          Width = 681
          Height = 88
          ActivePage = MainMenu
          Align = alClient
          Style = tsFlatButtons
          TabIndex = 0
          TabOrder = 0
          object MainMenu: TTabSheet
            Caption = 'MainMenu'
            DesignSize = (
              673
              54)
            object ButSetup: TSpeedButton
              Left = 614
              Top = 7
              Width = 41
              Height = 28
              Hint = #1054#1090#1082#1088#1099#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
              Anchors = [akTop, akRight]
              Flat = True
              Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C0060000C30E0000C30E00000000000000000000EAD999EAD999
                EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EBDB98EDDE9BEDDE
                9BEDDE9AEADA99EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EA
                D999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EBDB98
                DDC89ECCB188D1B489CCB28CE5D49AEADA99EAD999EAD999EAD999EAD999EAD9
                99EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EBDA99ECDC99EA
                D998EAD999F0E09BB393857941388B4C41754643D6C292ECDC9AEAD999EAD999
                EEDD98EAD997EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999ECDC
                99E6D69AD4C09DF0E09DEAD998F3E59CC3A18F9050479B5548885451DCCA93EF
                E099EADA98F0DF9BC6B6A9F3E4A8EAD996EAD999EAD999EAD999EAD999EAD999
                EAD999ECDB99F1E0A198635E7A4948D2C0ADF5E6A7D2B8979C6F679154479A5A
                4B8C5649B08B86DEC8ABF8EBADAC8B796E453FB59592F7E7AAEAD997EAD999EA
                D999EAD999EAD999EBDA99E4D59B88635F974F479E574D835B4E97645A874B44
                9456489C5B4B9A5949975A4A8D50458B51499C6B61885449945A4C7D4B42AB8F
                8FF0E19AEAD999EAD999EAD999EAD999EBDA98E4D5A6886464995348A3554895
                5B4C9458489A59499C5A4C9C56499C57499B57499B5A4B995A4A96594A98594A
                9B5A4C865049A48479F1E29CEAD999EAD999EAD999EAD999EAD999ECDC98ECD9
                A79F6C609C554998584B94594A8C564985514A9565659D72718E5F5C814F448D
                5A49975A4C9A5A4C8F5346B58F7AF3E5A0EAD999EAD999EAD999EAD999EAD999
                EAD999EAD998F2E5A49174668E54489C5C508C4F469A6C64DEC7A6EDDDA0F0E0
                A5ECDDA7CDB19E8B585294574C95594E865448C3AB85F0E09AEAD999EAD999EA
                D999EAD999EBDB98F3E39EF5E79ED8C7A37F4E469F594F915348996A67EEDBA4
                EDDE99EADA98EAD998EBDA98F0E19BDDC1A98A4E4D9E5A4F8F534884615BF7EC
                BBF2E39CF2E29CEAD999EBDB98DECCA690746AA28370997065945549A35B4E8C
                4F47D2BC9EEEDF99EAD999EAD999EAD999EAD999EAD998F1E49EB08771975348
                9C584D8A554BA17C6CA0806F9C857CF2E29CECDC99D5C2A0823A3D9B51479455
                42985B4896574891574FE8D799EBDA99EAD999EAD999EAD999EAD999EAD999ED
                DE99D5B79B864C3F9E59499D5745995244954F49805154F4E7A0ECDC98DCC8A4
                AF5E5BBE685AB57059A96F57AC725EAC7268ECDA9EEADA99EAD999EAD999EAD9
                99EAD999EAD999EBDC98E6C9AA9D6656B2715BB66F57BA6C57BB695DA46C6CF1
                E59EEBDB97DECDAA9B6D6AAD7D6DA7775EAE755AB5755EA56A5AE5D39BEBDB98
                EAD999EAD999EAD999EAD999EAD999EEE09BCEAA8AA76C58AE745BA97659B17C
                67B1786C9F7A7BF1E29CEAD998EBDBA2EADBA8F0E0A9D5C096A36C56BA745CAC
                6F56BC9991F2E3A5EADA98EAD999EAD999EAD998EBDC99ECDBA1B17C68B37057
                AC745C997A62EFDEB2F0DCA7ECDBAAEAD997EAD999EAD998EAD997EADA96F1E3
                B2AE7B6BB67058B27655AA6C5ACBA785ECDE9EEFE19CEEDF9BEFE19EE7D59CBB
                877AAC6E53BA765AAB6D59BAA189F0E19AEAD997EAD997EAD999EAD999EAD999
                EAD999EAD998F1E49DC29485B27158B07953AF7552AA6C54B4816EC3A080C9AA
                8CC39A7CAB7261AB7153AC7952B47454B16959DEBEAAEFE198EAD999EAD999EA
                D999EAD999EAD999EAD998EDDD9BBC9B85A56B54B87555B47655AC7953B77754
                AE7054A96C56AA6A55A96E56B77455AE7750AC7957B77556BE7456A16C56DAC6
                AAECDC98EAD999EAD999EAD999EAD999EBDA97E3D2AC8E695FAC7655B27655AA
                6D59A6715AAC6F54AC7256B8745ABB7158B27559B47157AB6F54A4715EAC7258
                B87753A46E4FA08278F1E19CEAD999EAD999EAD999EAD999EAD999EDDD96E2CF
                AE97725E926957CAA790E7D19EBF9C88A7735EB3725AB77159AE705BA97B6ACF
                AF9FECD6A5AE8A72946651AC8674F0E0A1EAD998EAD999EAD999EAD999EAD999
                EAD999EAD999EEDE97D8C8ABB7A494F0E19CEBDC99F1E59CD9B69DA26E54A976
                57A57161E6D49DEFE09AEBDC97EFDDAEB09894EFDEA0EBDA98EAD999EAD999EA
                D999EAD999EAD999EAD999EAD999EAD999ECDB98EFDE99EAD998EAD999EDDE9A
                CDA7939D684FA671549C6759DDC795EBDB99EAD999EAD997EFDF99EAD998EAD9
                99EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD999EA
                D999EAD999ECDC99D7BE9AB08B7FB08D7AB18E89E2CF9EEBDA98EAD999EAD998
                EAD998EAD998E9D898EAD999EAD999EAD999EAD999EAD999EAD999EAD999EAD9
                99EAD999EAD999EAD999EAD999EAD999ECDC99F0E19CF0E19CF0E19BEBDA98EA
                D999EAD999EAD998EAD999E9D898EAD99AE9D898EAD999EAD898}
              ParentShowHint = False
              ShowHint = True
              OnClick = ButSetupClick
            end
            object ButAddEvent: TSpeedButton
              Left = 256
              Top = 8
              Width = 137
              Height = 25
              Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1086#1073#1099#1090#1080#1077
              Flat = True
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clGreen
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = ButAddEventClick
            end
          end
          object EditMenu: TTabSheet
            Caption = 'EditMenu'
            ImageIndex = 1
            DesignSize = (
              673
              54)
            object ButEMBack: TSpeedButton
              Left = 0
              Top = 0
              Width = 57
              Height = 50
              Hint = #1053#1072#1079#1072#1076
              Flat = True
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clGreen
              Font.Height = -13
              Font.Name = 'Arial Black'
              Font.Style = [fsBold]
              Glyph.Data = {
                360C0000424D360C000000000000360000002800000020000000200000000100
                180000000000000C0000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                32E79032E68D2DE99A47FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFEEB06DE17501E68D2EE79033E79032E79032E79032E790
                32E79031E58A28EFBA7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                32E79032E4841CF9E3CDFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFCFBFFFFFFFFFFFFFFFFFFFAEADA
                E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5CFECAB65E27A0A
                E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                9033E79033E79033E79033E79033E79033E79033E79032E68F30ECAC65E27A0A
                E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                9033E79033E79033E79033E79033E79033E79033E79032E68E31FFFFFFFAEADA
                E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5D0FFFFFFFFFFFF
                FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                32E79032E4841CF9E3CCFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFDFBFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFEEAF6EE17501E68D2EE79033E79032E79032E79032E790
                32E79031E58A28EFBA80FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                32E79032E68D2DE99A46FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              ParentShowHint = False
              ShowHint = True
              OnClick = ButEMBackClick
            end
            object ButClearSel: TSpeedButton
              Left = 480
              Top = 8
              Width = 135
              Height = 33
              Caption = #1057#1085#1103#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1080#1077
              Flat = True
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clGreen
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object ButSelAll: TSpeedButton
              Left = 299
              Top = 8
              Width = 113
              Height = 33
              Anchors = [akTop]
              Caption = #1042#1099#1076#1077#1083#1080#1090#1100' '#1074#1089#1077
              Flat = True
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clGreen
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object ButDelEvent: TSpeedButton
              Left = 104
              Top = 8
              Width = 137
              Height = 33
              Caption = #1059#1076#1072#1083#1080#1090#1100
              Flat = True
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clRed
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = ButDelEventClick
            end
          end
        end
      end
      object MidPanel: TPanel
        Left = 0
        Top = 81
        Width = 683
        Height = 306
        Align = alClient
        Caption = 'MidPanel'
        TabOrder = 2
        object DialPanel: TPanel
          Left = 1
          Top = 235
          Width = 681
          Height = 70
          Align = alBottom
          Color = clCream
          TabOrder = 0
          Visible = False
          object Label3: TLabel
            Left = 136
            Top = 24
            Width = 43
            Height = 16
            Caption = 'Label3'
          end
          object Label1: TLabel
            Left = 8
            Top = 8
            Width = 117
            Height = 16
            Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1086#1073#1099#1090#1080#1077':'
          end
          object Label2: TLabel
            Left = 136
            Top = 8
            Width = 43
            Height = 16
            Caption = 'Label2'
          end
          object ButDialNo: TButton
            Left = 536
            Top = 29
            Width = 97
            Height = 33
            Caption = #1085#1077#1090
            TabOrder = 0
            OnClick = ButDialNoClick
          end
          object ButDialOk: TButton
            Left = 24
            Top = 29
            Width = 97
            Height = 33
            Caption = #1076#1072
            TabOrder = 1
            OnClick = ButDialOkClick
          end
        end
        object CurrentBase: TStringGrid
          Left = 1
          Top = 1
          Width = 681
          Height = 234
          Align = alClient
          Color = clCream
          ColCount = 3
          DefaultColWidth = 150
          FixedColor = clMenu
          FixedCols = 0
          RowCount = 2
          FixedRows = 0
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          GridLineWidth = 2
          Options = [goRowSizing]
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 1
          OnDblClick = CurrentBaseDblClick
          OnDrawCell = CurrentBaseDrawCell
          OnMouseDown = CurrentBaseMouseDown
          OnMouseUp = CurrentBaseMouseUp
          OnSelectCell = CurrentBaseSelectCell
          ColWidths = (
            150
            150
            150)
        end
      end
    end
    object EditWin: TTabSheet
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
      ImageIndex = 1
      object Panel1: TPanel
        Left = 0
        Top = 414
        Width = 683
        Height = 63
        Align = alBottom
        Color = clCream
        TabOrder = 0
        object ButEditBack: TSpeedButton
          Left = 0
          Top = 8
          Width = 57
          Height = 50
          Hint = #1053#1072#1079#1072#1076
          Flat = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -13
          Font.Name = 'Arial Black'
          Font.Style = [fsBold]
          Glyph.Data = {
            360C0000424D360C000000000000360000002800000020000000200000000100
            180000000000000C0000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
            5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
            2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
            32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
            32E79032E68D2DE99A47FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFEEB06DE17501E68D2EE79033E79032E79032E79032E790
            32E79031E58A28EFBA7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
            32E79032E4841CF9E3CDFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
            FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFCFBFFFFFFFFFFFFFFFFFFFAEADA
            E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
            32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
            7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5CFECAB65E27A0A
            E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
            32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
            9033E79033E79033E79033E79033E79033E79033E79032E68F30ECAC65E27A0A
            E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
            32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
            9033E79033E79033E79033E79033E79033E79033E79032E68E31FFFFFFFAEADA
            E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
            32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
            7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5D0FFFFFFFFFFFF
            FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
            32E79032E4841CF9E3CCFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
            FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFDFBFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFEEAF6EE17501E68D2EE79033E79032E79032E79032E790
            32E79031E58A28EFBA80FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
            32E79032E68D2DE99A46FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
            32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
            2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
            5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          OnClick = ButEditBackClick
        end
        object ButSaveEvent: TSpeedButton
          Left = 272
          Top = 16
          Width = 161
          Height = 33
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
          Flat = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          OnClick = ButSaveEventClick
        end
        object ButSaveas: TSpeedButton
          Left = 488
          Top = 16
          Width = 153
          Height = 33
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' '#1085#1086#1074#1086#1077
          Flat = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          OnClick = ButSaveasClick
        end
      end
      object Panel4: TPanel
        Left = 177
        Top = 0
        Width = 506
        Height = 414
        Align = alClient
        Color = clAqua
        TabOrder = 1
        object EventText: TGroupBox
          Left = 1
          Top = 1
          Width = 504
          Height = 72
          Align = alTop
          Caption = ' '#1054#1087#1080#1089#1072#1085#1080#1077' '
          TabOrder = 0
          object Memo3: TMemo
            Left = 2
            Top = 18
            Width = 500
            Height = 52
            Align = alClient
            ScrollBars = ssVertical
            TabOrder = 0
          end
        end
        object Panel5: TPanel
          Left = 1
          Top = 73
          Width = 504
          Height = 340
          Align = alClient
          Caption = 'Panel5'
          Color = clAqua
          TabOrder = 1
          object Panel8: TPanel
            Left = 1
            Top = 1
            Width = 502
            Height = 338
            Align = alClient
            Caption = 'Panel8'
            Color = clCream
            TabOrder = 0
            object PageControl3: TPageControl
              Left = 1
              Top = 1
              Width = 500
              Height = 336
              ActivePage = SignalTab
              Align = alClient
              TabIndex = 4
              TabOrder = 0
              object MainTab: TTabSheet
                Caption = 'MainTab'
                object But_date: TSpeedButton
                  Left = 322
                  Top = 15
                  Width = 121
                  Height = 33
                  Caption = #1047#1072#1076#1072#1085#1085#1072#1103' '#1076#1072#1090#1072
                  Flat = True
                  OnClick = But_dateClick
                end
                object But_daily: TSpeedButton
                  Left = 322
                  Top = 47
                  Width = 121
                  Height = 33
                  Caption = #1045#1078#1077#1076#1085#1077#1074#1085#1086
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clSilver
                  Font.Height = -13
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = But_dailyClick
                end
                object But_monthly: TSpeedButton
                  Left = 322
                  Top = 79
                  Width = 121
                  Height = 33
                  Caption = #1045#1078#1077#1084#1077#1089#1103#1095#1085#1086
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clSilver
                  Font.Height = -13
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = But_monthlyClick
                end
                object But_weekly: TSpeedButton
                  Left = 322
                  Top = 109
                  Width = 121
                  Height = 33
                  Caption = #1042' '#1076#1077#1085#1100' '#1085#1077#1076#1077#1083#1080
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clSilver
                  Font.Height = -13
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = But_weeklyClick
                end
                object TimeEvent: TSpeedButton
                  Left = 72
                  Top = 56
                  Width = 193
                  Height = 33
                  Caption = #1042#1088#1077#1084#1103': 24 : 59'
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -15
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = TimeEventClick
                end
                object DateEvent: TSpeedButton
                  Left = 72
                  Top = 16
                  Width = 193
                  Height = 33
                  Caption = '31 '#1089#1077#1085#1090#1103#1073#1088#1103' 2022'
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -15
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = DateEventClick
                end
                object RemEvent: TSpeedButton
                  Left = 112
                  Top = 96
                  Width = 105
                  Height = 33
                  Caption = ' '#1085#1077#1090
                  Flat = True
                end
                object Label9: TLabel
                  Left = 8
                  Top = 24
                  Width = 39
                  Height = 16
                  Caption = #1044#1072#1090#1072': '
                end
                object Label10: TLabel
                  Left = 8
                  Top = 64
                  Width = 50
                  Height = 16
                  Caption = #1042#1088#1077#1084#1103': '
                end
                object Label11: TLabel
                  Left = 8
                  Top = 104
                  Width = 98
                  Height = 16
                  Caption = #1053#1072#1087#1086#1084#1080#1085#1072#1085#1080#1077': '
                end
                object Label12: TLabel
                  Left = 8
                  Top = 152
                  Width = 147
                  Height = 16
                  Caption = #1047#1074#1091#1082#1086#1074#1086#1077' '#1089#1086#1086#1073#1097#1077#1085#1080#1077': '
                end
                object SoundEvent: TSpeedButton
                  Left = 160
                  Top = 152
                  Width = 89
                  Height = 22
                  Caption = #1085#1077#1090
                  Flat = True
                  OnClick = SoundEventClick
                end
                object RingEvent: TSpeedButton
                  Left = 160
                  Top = 184
                  Width = 89
                  Height = 25
                  Caption = #1085#1077#1090
                  Flat = True
                  OnClick = RingEventClick
                end
                object Label13: TLabel
                  Left = 8
                  Top = 184
                  Width = 51
                  Height = 16
                  Caption = #1047#1074#1086#1085#1086#1082':'
                end
                object EventNum: TLabel
                  Left = 8
                  Top = 272
                  Width = 64
                  Height = 16
                  Caption = 'EventNum'
                end
                object Is_seleb: TCheckBox
                  Left = 8
                  Top = 233
                  Width = 249
                  Height = 17
                  Caption = #1085#1077' '#1088#1072#1073#1086#1095#1080#1081' '#1076#1077#1085#1100' ('#1087#1088#1072#1079#1076#1085#1080#1082', '#1074#1099#1093#1086#1076#1085#1086#1081')'
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGray
                  Font.Height = -12
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  TabOrder = 0
                  OnClick = Is_selebClick
                  OnMouseDown = Is_selebMouseDown
                end
                object At_seleb: TCheckBox
                  Left = 302
                  Top = 231
                  Width = 179
                  Height = 18
                  Caption = #1074#1082#1083#1102#1095#1072#1090#1100' '#1074' '#1087#1088#1072#1079#1076#1085#1080#1082#1080
                  TabOrder = 1
                end
              end
              object DayTab: TTabSheet
                Caption = 'DayTab'
                ImageIndex = 1
                DesignSize = (
                  492
                  305)
                object DayBack: TSpeedButton
                  Left = 8
                  Top = 216
                  Width = 57
                  Height = 50
                  Hint = #1053#1072#1079#1072#1076
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -13
                  Font.Name = 'Arial Black'
                  Font.Style = [fsBold]
                  Glyph.Data = {
                    360C0000424D360C000000000000360000002800000020000000200000000100
                    180000000000000C0000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                    5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                    2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                    32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                    32E79032E68D2DE99A47FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFEEB06DE17501E68D2EE79033E79032E79032E79032E790
                    32E79031E58A28EFBA7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                    32E79032E4841CF9E3CDFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                    FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFCFBFFFFFFFFFFFFFFFFFFFAEADA
                    E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                    7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5CFECAB65E27A0A
                    E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                    9033E79033E79033E79033E79033E79033E79033E79032E68F30ECAC65E27A0A
                    E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                    9033E79033E79033E79033E79033E79033E79033E79032E68E31FFFFFFFAEADA
                    E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                    7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5D0FFFFFFFFFFFF
                    FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                    32E79032E4841CF9E3CCFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                    FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFDFBFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFEEAF6EE17501E68D2EE79033E79032E79032E79032E790
                    32E79031E58A28EFBA80FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                    32E79032E68D2DE99A46FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                    32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                    2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                    5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = True
                  OnClick = DayBackClick
                end
                object At_year: TCheckBox
                  Left = 104
                  Top = 32
                  Width = 57
                  Height = 17
                  Caption = #1075#1086#1076
                  TabOrder = 0
                  OnClick = At_yearClick
                end
                object At_month: TCheckBox
                  Left = 192
                  Top = 32
                  Width = 65
                  Height = 17
                  Caption = #1084#1077#1089#1103#1094
                  Checked = True
                  State = cbChecked
                  TabOrder = 1
                  OnClick = At_monthClick
                end
                object At_day: TCheckBox
                  Left = 288
                  Top = 32
                  Width = 57
                  Height = 17
                  Caption = #1076#1077#1085#1100
                  Checked = True
                  State = cbChecked
                  TabOrder = 2
                  OnClick = At_dayClick
                end
                object DateTimePicker1: TDateTimePicker
                  Left = 172
                  Top = 97
                  Width = 114
                  Height = 24
                  Anchors = [akTop]
                  BevelInner = bvNone
                  BevelOuter = bvNone
                  CalAlignment = dtaLeft
                  Date = 44737.6649619213
                  Time = 44737.6649619213
                  DateFormat = dfShort
                  DateMode = dmComboBox
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -13
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  Kind = dtkDate
                  ParseInput = False
                  ParentFont = False
                  TabOrder = 3
                  OnChange = DateTimePicker1Change
                end
              end
              object WeekTab: TTabSheet
                Caption = 'WeekTab'
                ImageIndex = 2
                object WeekBack: TSpeedButton
                  Left = 8
                  Top = 216
                  Width = 57
                  Height = 50
                  Hint = #1053#1072#1079#1072#1076
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -13
                  Font.Name = 'Arial Black'
                  Font.Style = [fsBold]
                  Glyph.Data = {
                    360C0000424D360C000000000000360000002800000020000000200000000100
                    180000000000000C0000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                    5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                    2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                    32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                    32E79032E68D2DE99A47FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFEEB06DE17501E68D2EE79033E79032E79032E79032E790
                    32E79031E58A28EFBA7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                    32E79032E4841CF9E3CDFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                    FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFCFBFFFFFFFFFFFFFFFFFFFAEADA
                    E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                    7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5CFECAB65E27A0A
                    E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                    9033E79033E79033E79033E79033E79033E79033E79032E68F30ECAC65E27A0A
                    E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                    9033E79033E79033E79033E79033E79033E79033E79032E68E31FFFFFFFAEADA
                    E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                    7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5D0FFFFFFFFFFFF
                    FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                    32E79032E4841CF9E3CCFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                    FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFDFBFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFEEAF6EE17501E68D2EE79033E79032E79032E79032E790
                    32E79031E58A28EFBA80FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                    32E79032E68D2DE99A46FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                    32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                    2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                    5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = True
                  OnClick = WeekBackClick
                end
                object At_mon: TCheckBox
                  Left = 96
                  Top = 48
                  Width = 113
                  Height = 17
                  Caption = #1087#1086#1085#1077#1076#1077#1083#1100#1085#1080#1082
                  TabOrder = 0
                  OnClick = At_monClick
                end
                object At_fri: TCheckBox
                  Left = 232
                  Top = 48
                  Width = 113
                  Height = 17
                  Caption = #1087#1103#1090#1085#1080#1094#1072
                  TabOrder = 1
                  OnClick = At_friClick
                end
                object At_sat: TCheckBox
                  Left = 232
                  Top = 72
                  Width = 113
                  Height = 17
                  Caption = #1089#1091#1073#1073#1086#1090#1072
                  TabOrder = 2
                  OnClick = At_satClick
                end
                object At_tue: TCheckBox
                  Left = 96
                  Top = 72
                  Width = 113
                  Height = 17
                  Caption = #1074#1090#1086#1088#1085#1080#1082
                  TabOrder = 3
                  OnClick = At_tueClick
                end
                object At_wed: TCheckBox
                  Left = 96
                  Top = 96
                  Width = 113
                  Height = 17
                  Caption = #1089#1088#1077#1076#1072
                  TabOrder = 4
                  OnClick = At_wedClick
                end
                object At_sun: TCheckBox
                  Left = 232
                  Top = 96
                  Width = 113
                  Height = 17
                  Caption = #1074#1086#1089#1082#1088#1077#1089#1077#1085#1100#1077
                  TabOrder = 5
                  OnClick = At_sunClick
                end
                object At_thur: TCheckBox
                  Left = 96
                  Top = 120
                  Width = 113
                  Height = 17
                  Caption = #1095#1077#1090#1074#1077#1088#1075
                  TabOrder = 6
                  OnClick = At_thurClick
                end
              end
              object TimeTab: TTabSheet
                Caption = 'TimeTab'
                ImageIndex = 3
                object IncHour: TSpeedButton
                  Left = 172
                  Top = 88
                  Width = 57
                  Height = 30
                  Caption = '01'
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clSilver
                  Font.Height = -12
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = IncHourClick
                  OnMouseDown = IncHourMouseDown
                  OnMouseUp = IncHourMouseUp
                end
                object IncMinute: TSpeedButton
                  Left = 248
                  Top = 88
                  Width = 57
                  Height = 30
                  Caption = '01'
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clSilver
                  Font.Height = -12
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = IncMinuteClick
                  OnMouseDown = IncMinuteMouseDown
                  OnMouseUp = IncMinuteMouseUp
                end
                object DecHour: TSpeedButton
                  Left = 171
                  Top = 144
                  Width = 57
                  Height = 30
                  Caption = '23'
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clSilver
                  Font.Height = -12
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = DecHourClick
                  OnMouseDown = DecHourMouseDown
                  OnMouseUp = DecHourMouseUp
                end
                object DecMinute: TSpeedButton
                  Left = 248
                  Top = 144
                  Width = 57
                  Height = 30
                  Caption = '59'
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clSilver
                  Font.Height = -12
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = DecMinuteClick
                  OnMouseDown = DecMinuteMouseDown
                  OnMouseUp = DecMinuteMouseUp
                end
                object TimeBack: TSpeedButton
                  Left = 8
                  Top = 216
                  Width = 57
                  Height = 50
                  Hint = #1053#1072#1079#1072#1076
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -13
                  Font.Name = 'Arial Black'
                  Font.Style = [fsBold]
                  Glyph.Data = {
                    360C0000424D360C000000000000360000002800000020000000200000000100
                    180000000000000C0000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                    5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                    2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                    32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                    32E79032E68D2DE99A47FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFEEB06DE17501E68D2EE79033E79032E79032E79032E790
                    32E79031E58A28EFBA7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                    32E79032E4841CF9E3CDFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                    FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFCFBFFFFFFFFFFFFFFFFFFFAEADA
                    E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                    7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5CFECAB65E27A0A
                    E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                    9033E79033E79033E79033E79033E79033E79033E79032E68F30ECAC65E27A0A
                    E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                    9033E79033E79033E79033E79033E79033E79033E79032E68E31FFFFFFFAEADA
                    E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                    7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5D0FFFFFFFFFFFF
                    FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                    32E79032E4841CF9E3CCFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                    FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFDFBFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFEEAF6EE17501E68D2EE79033E79032E79032E79032E790
                    32E79031E58A28EFBA80FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                    32E79032E68D2DE99A46FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                    32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                    2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                    5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = True
                  OnClick = TimeBackClick
                end
                object FUseHour: TCheckBox
                  Left = 176
                  Top = 64
                  Width = 49
                  Height = 17
                  Caption = #1095#1072#1089#1099
                  Checked = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGray
                  Font.Height = -12
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  State = cbChecked
                  TabOrder = 0
                  OnClick = FUseHourClick
                  OnMouseDown = FUseHourMouseDown
                end
                object FUseMinute: TCheckBox
                  Left = 240
                  Top = 64
                  Width = 65
                  Height = 17
                  Caption = #1084#1080#1085#1091#1090#1099
                  Checked = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGray
                  Font.Height = -12
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  State = cbChecked
                  TabOrder = 1
                  OnClick = FUseMinuteClick
                  OnMouseDown = FUseMinuteMouseDown
                end
                object TextHour: TEdit
                  Left = 189
                  Top = 123
                  Width = 25
                  Height = 17
                  BevelInner = bvNone
                  BevelKind = bkFlat
                  BevelOuter = bvNone
                  BiDiMode = bdLeftToRight
                  BorderStyle = bsNone
                  Color = clBtnFace
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -16
                  Font.Name = 'Verdana'
                  Font.Style = [fsBold]
                  ParentBiDiMode = False
                  ParentFont = False
                  TabOrder = 2
                  Text = '00'
                end
                object TextMinute: TEdit
                  Left = 266
                  Top = 123
                  Width = 25
                  Height = 17
                  BorderStyle = bsNone
                  Color = clBtnFace
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -16
                  Font.Name = 'Verdana'
                  Font.Style = [fsBold]
                  ParentFont = False
                  TabOrder = 3
                  Text = '00'
                end
              end
              object SignalTab: TTabSheet
                Caption = 'SignalTab'
                ImageIndex = 4
                object OpenSound: TSpeedButton
                  Left = 264
                  Top = 56
                  Width = 65
                  Height = 25
                  Caption = #1085#1072#1081#1090#1080'...'
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGray
                  Font.Height = -13
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = OpenSoundClick
                end
                object Label4: TLabel
                  Left = 128
                  Top = 178
                  Width = 192
                  Height = 16
                  Caption = #1055#1088#1086#1076#1086#1083#1078#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1079#1074#1086#1085#1082#1072': '
                end
                object SigBack: TSpeedButton
                  Left = 8
                  Top = 216
                  Width = 57
                  Height = 50
                  Hint = #1053#1072#1079#1072#1076
                  Flat = True
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -13
                  Font.Name = 'Arial Black'
                  Font.Style = [fsBold]
                  Glyph.Data = {
                    360C0000424D360C000000000000360000002800000020000000200000000100
                    180000000000000C0000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                    5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                    2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                    32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                    32E79032E68D2DE99A47FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFEEB06DE17501E68D2EE79033E79032E79032E79032E790
                    32E79031E58A28EFBA7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                    32E79032E4841CF9E3CDFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                    FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFCFBFFFFFFFFFFFFFFFFFFFAEADA
                    E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                    7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5CFECAB65E27A0A
                    E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                    9033E79033E79033E79033E79033E79033E79033E79032E68F30ECAC65E27A0A
                    E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
                    9033E79033E79033E79033E79033E79033E79033E79032E68E31FFFFFFFAEADA
                    E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
                    32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
                    7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5D0FFFFFFFFFFFF
                    FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
                    32E79032E4841CF9E3CCFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
                    FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFDFBFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFEEAF6EE17501E68D2EE79033E79032E79032E79032E790
                    32E79031E58A28EFBA80FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
                    32E79032E68D2DE99A46FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
                    32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
                    2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
                    5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
                  ParentFont = False
                  ParentShowHint = False
                  ShowHint = True
                  OnClick = SigBackClick
                end
                object Add_sound: TCheckBox
                  Left = 128
                  Top = 29
                  Width = 217
                  Height = 17
                  Caption = #1055#1086#1076#1072#1074#1072#1090#1100' '#1079#1074#1091#1082#1086#1074#1086#1081' '#1089#1080#1075#1085#1072#1083
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGray
                  Font.Height = -13
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  TabOrder = 0
                end
                object MediaPlayer1: TMediaPlayer
                  Left = 163
                  Top = 88
                  Width = -1
                  Height = 25
                  EnabledButtons = [btPlay, btStop, btEject]
                  VisibleButtons = [btPlay, btStop]
                  TabOrder = 1
                end
                object SigFiles: TComboBox
                  Left = 128
                  Top = 58
                  Width = 129
                  Height = 23
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGreen
                  Font.Height = -12
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ItemHeight = 0
                  ParentFont = False
                  TabOrder = 2
                  OnChange = SigFilesChange
                end
                object Add_ring: TCheckBox
                  Left = 128
                  Top = 152
                  Width = 153
                  Height = 17
                  Caption = #1042#1082#1083#1102#1095#1072#1090#1100' '#1079#1074#1086#1085#1086#1082
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clGray
                  Font.Height = -13
                  Font.Name = 'Arial'
                  Font.Style = [fsBold]
                  ParentFont = False
                  TabOrder = 3
                end
                object ShowRingDelay: TEdit
                  Left = 320
                  Top = 175
                  Width = 41
                  Height = 24
                  TabOrder = 4
                  Text = '10'
                end
                object RingDelay: TUpDown
                  Left = 361
                  Top = 175
                  Width = 16
                  Height = 24
                  Associate = ShowRingDelay
                  Min = 0
                  Max = 99
                  Position = 10
                  TabOrder = 5
                  Wrap = False
                end
              end
            end
          end
        end
      end
      object Panel10: TPanel
        Left = 0
        Top = 0
        Width = 177
        Height = 414
        Align = alLeft
        Caption = 'Panel10'
        TabOrder = 2
        object StringGrid1: TStringGrid
          Left = 1
          Top = 1
          Width = 175
          Height = 412
          Align = alClient
          ColCount = 2
          FixedCols = 0
          RowCount = 1
          FixedRows = 0
          TabOrder = 0
        end
      end
    end
    object SetupWin: TTabSheet
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      ImageIndex = 2
      object Panel3: TPanel
        Left = 0
        Top = 414
        Width = 683
        Height = 63
        Align = alBottom
        Color = clCream
        TabOrder = 0
        object ButBack: TSpeedButton
          Left = 0
          Top = 8
          Width = 57
          Height = 50
          Hint = #1053#1072#1079#1072#1076
          Flat = True
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clGreen
          Font.Height = -13
          Font.Name = 'Arial Black'
          Font.Style = [fsBold]
          Glyph.Data = {
            360C0000424D360C000000000000360000002800000020000000200000000100
            180000000000000C0000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
            5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
            2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
            32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
            32E79032E68D2DE99A47FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFEEB06DE17501E68D2EE79033E79032E79032E79032E790
            32E79031E58A28EFBA7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
            32E79032E4841CF9E3CDFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
            FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFCFBFFFFFFFFFFFFFFFFFFFAEADA
            E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
            32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
            7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5CFECAB65E27A0A
            E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
            32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
            9033E79033E79033E79033E79033E79033E79033E79032E68F30ECAC65E27A0A
            E68F30E79032E79032E79032E79032E79032E79032E79032E79032E79032E790
            32E79032E79032E79033E79033E79033E79033E79033E79033E79033E79033E7
            9033E79033E79033E79033E79033E79033E79033E79032E68E31FFFFFFFAEADA
            E58722E4841CE79032E79032E79032E79032E79032E79032E79032E79032E790
            32E79032E79033E38015E17A09E17A0AE17A0AE17A0AE17A0AE17A0AE17A0AE1
            7A0AE17A0AE17A0AE17A0AE17A0AE17A0AE17A0BDF6F00F9E5D0FFFFFFFFFFFF
            FFFFFFF4CEA6E17908E68B28E79033E79031E79032E79032E79032E79032E790
            32E79032E4841CF9E3CCFFFFFFFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFE
            FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFDFBFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFEEAF6EE17501E68D2EE79033E79032E79032E79032E790
            32E79031E58A28EFBA80FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFEFCF9E99A44E27D0EE78F31E79032E79032E790
            32E79032E68D2DE99A46FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E2CAE48218E58621E79033E790
            32E79032E79033E07601FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3C697E17704E68C
            2BE79033E79032E37F14FAEDDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBA8
            5FE17603E68E2FE58926F2C28EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFEF8F2E69135E37C0EEA9E4BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFF5D2ACF4D1ACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          OnClick = ButBackClick
        end
      end
      object Setup: TPageControl
        Left = 0
        Top = 0
        Width = 683
        Height = 414
        ActivePage = PageSetup
        Align = alClient
        MultiLine = True
        ScrollOpposite = True
        Style = tsFlatButtons
        TabIndex = 0
        TabOrder = 1
        TabWidth = 150
        object PageSetup: TTabSheet
          Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
          object Label8: TLabel
            Left = 376
            Top = 16
            Width = 91
            Height = 16
            Caption = #1063#1072#1089#1086#1074#1086#1081' '#1087#1086#1103#1089
          end
          object DefShowWarnWindow: TCheckBox
            Left = 16
            Top = 16
            Width = 225
            Height = 17
            Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1086#1082#1085#1086' '#1089' '#1086#1096#1080#1073#1082#1072#1084#1080
            Checked = True
            State = cbChecked
            TabOrder = 0
          end
          object ListTimeZone: TComboBox
            Left = 480
            Top = 13
            Width = 145
            Height = 24
            ItemHeight = 16
            ItemIndex = 1
            TabOrder = 1
            Text = 'UTC+3   '#1052#1086#1089#1082#1074#1072
            Items.Strings = (
              'UTC+2   '#1050#1072#1083#1080#1085#1080#1085#1075#1088#1072#1076
              'UTC+3   '#1052#1086#1089#1082#1074#1072
              'UTC+4   '#1057#1072#1084#1072#1088#1072
              'UTC+5   '#1045#1082#1072#1090#1077#1088#1080#1085#1073#1091#1088#1075
              'UTC+6   '#1054#1084#1089#1082
              'UTC+7   '#1050#1088#1072#1089#1085#1086#1103#1088#1089#1082
              'UTC+8   '#1048#1088#1082#1091#1090#1089#1082
              'UTC+9   '#1071#1082#1091#1090#1089#1082
              'UTC+10  '#1042#1083#1072#1076#1080#1074#1086#1089#1090#1086#1082
              'UTC+11  '#1052#1072#1075#1072#1076#1072#1085
              'UTC+12  '#1050#1072#1084#1095#1072#1090#1082#1072)
          end
          object Button1: TButton
            Left = 24
            Top = 320
            Width = 75
            Height = 25
            Caption = 'Button1'
            TabOrder = 2
            OnClick = Button1Click
          end
        end
        object PageRing: TTabSheet
          Caption = ' Ring '
          ImageIndex = 1
          object RingControl: TPageControl
            Left = 0
            Top = 0
            Width = 675
            Height = 383
            ActivePage = RingHandPage
            Align = alClient
            TabIndex = 2
            TabOrder = 0
            TabPosition = tpBottom
            object RignStatePage: TTabSheet
              Caption = 'RignStatePage'
              DesignSize = (
                667
                354)
              object RingButton: TSpeedButton
                Left = 17
                Top = 265
                Width = 121
                Height = 33
                Anchors = [akBottom]
                Caption = #1047#1074#1086#1085#1086#1082
                Flat = True
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clGreen
                Font.Height = -13
                Font.Name = 'Arial'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = RingButtonClick
              end
              object ButSound: TSpeedButton
                Left = 179
                Top = 265
                Width = 121
                Height = 33
                Anchors = [akBottom]
                Caption = #1047#1074#1091#1082#1086#1074#1086#1081' '#1089#1080#1075#1085#1072#1083
                Flat = True
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clGreen
                Font.Height = -13
                Font.Name = 'Arial'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = ButSoundClick
              end
              object AlarmButton: TSpeedButton
                Left = 347
                Top = 265
                Width = 121
                Height = 33
                Anchors = [akBottom]
                Caption = #1058#1088#1077#1074#1086#1075#1072
                Flat = True
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clRed
                Font.Height = -19
                Font.Name = 'Arial Narrow'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = AlarmButtonClick
              end
              object But_Fire: TSpeedButton
                Left = 507
                Top = 265
                Width = 121
                Height = 33
                Anchors = [akBottom]
                Caption = #1055#1086#1078#1072#1088
                Flat = True
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clRed
                Font.Height = -19
                Font.Name = 'Arial Narrow'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = But_FireClick
              end
              object Label14: TLabel
                Left = 8
                Top = 48
                Width = 95
                Height = 16
                Caption = #1055#1086#1076#1082#1083#1102#1095#1077#1085#1080#1077':'
              end
              object Label15: TLabel
                Left = 8
                Top = 128
                Width = 115
                Height = 16
                Caption = #1042#1089#1090#1088#1086#1077#1085#1085#1099#1077' RTC:'
              end
              object Label16: TLabel
                Left = 8
                Top = 168
                Width = 80
                Height = 16
                Caption = 'RTC DS3231:'
              end
              object Label17: TLabel
                Left = 8
                Top = 208
                Width = 83
                Height = 16
                Caption = #1056#1072#1089#1087#1080#1089#1072#1085#1080#1077':'
              end
              object Label18: TLabel
                Left = 8
                Top = 88
                Width = 48
                Height = 16
                Caption = #1056#1077#1078#1080#1084':'
              end
              object RingLinkState: TLabel
                Left = 152
                Top = 48
                Width = 94
                Height = 16
                Caption = #1085#1077' '#1087#1086#1076#1082#1083#1102#1095#1077#1085
              end
              object RingModeState: TLabel
                Left = 152
                Top = 88
                Width = 92
                Height = 16
                Caption = #1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085
              end
              object RingEmbRTC: TLabel
                Left = 152
                Top = 128
                Width = 172
                Height = 16
                Caption = #1089#1086#1089#1090#1086#1103#1085#1080#1077' '#1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
              end
              object Label22: TLabel
                Left = 152
                Top = 168
                Width = 172
                Height = 16
                Caption = #1089#1086#1089#1090#1086#1103#1085#1080#1077' '#1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
              end
              object Label23: TLabel
                Left = 152
                Top = 208
                Width = 172
                Height = 16
                Caption = #1089#1086#1089#1090#1086#1103#1085#1080#1077' '#1085#1077' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1086
              end
              object ButStateRing: TSpeedButton
                Left = 424
                Top = 16
                Width = 129
                Height = 22
                Caption = #1054#1087#1088#1086#1089#1080#1090#1100' Ring'
                OnClick = ButStateRingClick
              end
              object DefRingUnited: TCheckBox
                Left = 8
                Top = 8
                Width = 225
                Height = 17
                Caption = ' '#1055#1086#1076#1082#1083#1102#1095#1080#1090#1100' '#1082#1086#1084#1087#1083#1077#1082#1089' Ring'
                Checked = True
                State = cbChecked
                TabOrder = 0
              end
            end
            object RingCOMPage: TTabSheet
              Caption = 'RingCOMPage'
              ImageIndex = 1
              object DefRingComm: TCheckBox
                Left = 8
                Top = 8
                Width = 249
                Height = 17
                Caption = #1057#1086#1077#1076#1080#1085#1077#1085#1080#1077' '#1089' Ring  '#1087#1086' COM '#1087#1086#1088#1090#1091
                Checked = True
                State = cbChecked
                TabOrder = 0
              end
              object GroupBox1: TGroupBox
                Left = 8
                Top = 40
                Width = 409
                Height = 65
                Caption = #1057#1054#1052' '#1087#1086#1088#1090' '#1089' Ring '
                TabOrder = 1
                object COMList: TComboBox
                  Left = 24
                  Top = 24
                  Width = 105
                  Height = 24
                  ItemHeight = 0
                  TabOrder = 0
                  Text = 'COM -'
                end
                object COMConnect: TButton
                  Left = 160
                  Top = 24
                  Width = 105
                  Height = 25
                  Caption = #1055#1086#1076#1082#1083#1102#1095#1077#1085#1080#1077
                  TabOrder = 1
                  OnClick = COMConnectClick
                end
                object ButCommSetup: TButton
                  Left = 288
                  Top = 24
                  Width = 97
                  Height = 25
                  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
                  Enabled = False
                  TabOrder = 2
                  OnClick = ButCommSetupClick
                end
              end
            end
            object RingHandPage: TTabSheet
              Caption = 'RingHandPage'
              ImageIndex = 2
              object GroupBox2: TGroupBox
                Left = 16
                Top = 10
                Width = 409
                Height = 136
                Caption = ' '#1057#1080#1085#1093#1088#1086#1085#1080#1079#1072#1094#1080#1103' Ring '
                TabOrder = 0
                object Label6: TLabel
                  Left = 248
                  Top = 24
                  Width = 152
                  Height = 16
                  Caption = #1055#1077#1088#1077#1076#1072#1095#1072' '#1089' '#1079#1072#1076#1077#1088#1078#1082#1086#1081
                end
                object FSyncTime: TCheckBox
                  Left = 16
                  Top = 56
                  Width = 73
                  Height = 17
                  Caption = #1042#1088#1077#1084#1103
                  Checked = True
                  State = cbChecked
                  TabOrder = 0
                end
                object FSyncShed: TCheckBox
                  Left = 16
                  Top = 24
                  Width = 97
                  Height = 17
                  Caption = #1056#1072#1089#1087#1080#1089#1072#1085#1080#1077
                  Checked = True
                  State = cbChecked
                  TabOrder = 1
                end
                object ButStart: TButton
                  Left = 152
                  Top = 24
                  Width = 73
                  Height = 25
                  Caption = #1057#1090#1072#1088#1090
                  TabOrder = 2
                  OnClick = ButStartClick
                end
                object ButStop: TButton
                  Left = 152
                  Top = 56
                  Width = 75
                  Height = 25
                  Caption = #1057#1090#1086#1087
                  TabOrder = 3
                  OnClick = ButStopClick
                end
                object TrDelay: TEdit
                  Left = 264
                  Top = 48
                  Width = 65
                  Height = 24
                  TabOrder = 4
                  Text = '200'
                end
                object COMDelayBF: TUpDown
                  Left = 329
                  Top = 48
                  Width = 16
                  Height = 24
                  Associate = TrDelay
                  Min = 0
                  Max = 1000
                  Position = 200
                  TabOrder = 5
                  Wrap = False
                end
                object ProgressBar1: TProgressBar
                  Left = 16
                  Top = 88
                  Width = 377
                  Height = 9
                  Min = 0
                  Max = 100
                  TabOrder = 6
                end
              end
              object butch: TButton
                Left = 448
                Top = 17
                Width = 129
                Height = 25
                Caption = #1055#1086#1090#1086#1082
                TabOrder = 1
                OnClick = butchClick
              end
            end
            object RingSetupPage: TTabSheet
              Caption = 'RingSetupPage'
              ImageIndex = 3
              object Label5: TLabel
                Left = 16
                Top = 36
                Width = 245
                Height = 16
                Caption = #1047#1072#1076#1077#1088#1078#1082#1072' '#1074#1082#1083#1102#1095#1077#1085#1080#1103' '#1091#1089#1080#1083#1080#1090#1077#1083#1103', '#1089#1077#1082
              end
              object Label7: TLabel
                Left = 16
                Top = 68
                Width = 251
                Height = 16
                Caption = #1047#1072#1076#1077#1088#1078#1082#1072' '#1086#1090#1082#1083#1102#1095#1077#1085#1080#1103' '#1091#1089#1080#1083#1080#1090#1077#1083#1103', '#1089#1077#1082
              end
              object UpBoosterDelayW: TEdit
                Left = 288
                Top = 33
                Width = 41
                Height = 24
                TabOrder = 0
                Text = '3'
              end
              object UpBoosterDelay: TUpDown
                Left = 329
                Top = 33
                Width = 16
                Height = 24
                Associate = UpBoosterDelayW
                Min = 0
                Max = 99
                Position = 3
                TabOrder = 1
                Wrap = True
              end
              object DownBoosterDelay: TUpDown
                Left = 329
                Top = 65
                Width = 16
                Height = 24
                Associate = DownBoosterDelayW
                Min = 0
                Max = 99
                Position = 1
                TabOrder = 2
                Wrap = False
              end
              object DownBoosterDelayW: TEdit
                Left = 288
                Top = 65
                Width = 41
                Height = 24
                TabOrder = 3
                Text = '1'
              end
            end
          end
        end
        object PageManual: TTabSheet
          Caption = ' '#1054#1087#1080#1089#1072#1085#1080#1077' '
          ImageIndex = 2
          object Manual: TMemo
            Left = 0
            Top = 0
            Width = 675
            Height = 383
            Align = alClient
            Lines.Strings = (
              'Manual')
            ScrollBars = ssBoth
            TabOrder = 0
          end
        end
        object PageLog: TTabSheet
          Caption = '   '#1046#1091#1088#1085#1072#1083'   '
          ImageIndex = 3
          object Memo1: TMemo
            Left = 0
            Top = 0
            Width = 675
            Height = 276
            Align = alClient
            Lines.Strings = (
              'Memo1')
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object Memo2: TMemo
            Left = 0
            Top = 276
            Width = 675
            Height = 66
            Align = alBottom
            Lines.Strings = (
              'Memo2')
            ScrollBars = ssBoth
            TabOrder = 1
          end
          object Panel6: TPanel
            Left = 0
            Top = 342
            Width = 675
            Height = 41
            Align = alBottom
            TabOrder = 2
            object ButSupCheck: TSpeedButton
              Left = 533
              Top = 4
              Width = 129
              Height = 33
              Caption = #1055#1088#1086#1074#1077#1088#1082#1072' '
              OnClick = ButSupCheckClick
            end
            object ButClear: TSpeedButton
              Left = 376
              Top = 5
              Width = 137
              Height = 30
              Caption = #1054#1095#1080#1089#1090#1080#1090#1100
              OnClick = ButClearClick
            end
            object CheckBox1: TCheckBox
              Left = 9
              Top = 15
              Width = 120
              Height = 17
              Caption = #1042#1077#1089#1090#1080' '#1078#1091#1088#1085#1072#1083
              TabOrder = 0
            end
            object FlagLog: TCheckBox
              Left = 272
              Top = 2
              Width = 97
              Height = 17
              Caption = #1046#1091#1088#1085#1072#1083
              TabOrder = 1
            end
            object FlagBuffer: TCheckBox
              Left = 272
              Top = 22
              Width = 97
              Height = 17
              Caption = #1041#1091#1092#1077#1088
              TabOrder = 2
            end
          end
        end
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 506
    Width = 691
    Height = 21
    Panels = <
      item
        Text = #1047#1074#1086#1085#1086#1082
        Width = 50
      end>
    SimplePanel = False
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 368
    Top = 496
  end
  object Timer2: TTimer
    Interval = 300
    OnTimer = Timer2Timer
    Left = 408
    Top = 496
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'mp3'
    FileName = '*.mp3'
    Filter = '*.mp3|*.mp3|*.wav|*.wav'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 448
    Top = 496
  end
end
