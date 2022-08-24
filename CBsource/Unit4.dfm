object MessWindow: TMessWindow
  Left = 478
  Top = 275
  ActiveControl = Memo1
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsDialog
  Caption = #1042#1085#1080#1084#1072#1085#1080#1077
  ClientHeight = 158
  ClientWidth = 489
  Color = clBtnFace
  DefaultMonitor = dmMainForm
  DockSite = True
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Arial'
  Font.Style = [fsBold]
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 117
    Width = 489
    Height = 41
    Align = alBottom
    TabOrder = 0
    object Button: TButton
      Left = 184
      Top = 8
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonClick
    end
    object MessPlayer: TMediaPlayer
      Left = 8
      Top = 8
      Width = 57
      Height = 30
      EnabledButtons = [btPlay, btStop]
      VisibleButtons = [btPlay, btStop]
      Visible = False
      TabOrder = 1
    end
    object UnSetWarn: TCheckBox
      Left = 320
      Top = 14
      Width = 161
      Height = 17
      Caption = #1041#1086#1083#1100#1096#1077' '#1085#1077' '#1087#1086#1082#1072#1079#1099#1074#1072#1090#1100
      TabOrder = 2
      Visible = False
      OnClick = UnSetWarnClick
    end
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 489
    Height = 117
    Align = alClient
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
end
