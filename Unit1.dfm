object Form1: TForm1
  Left = 499
  Top = 234
  BorderStyle = bsDialog
  Caption = 'notAnotherPingPongGame'
  ClientHeight = 596
  ClientWidth = 964
  Color = clBtnFace
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyPress = FormKeyPress
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object background: TShape
    Left = 0
    Top = 0
    Width = 964
    Height = 596
    Align = alClient
    Brush.Color = clActiveCaption
  end
  object hero: TImage
    Left = 416
    Top = 304
    Width = 66
    Height = 112
    AutoSize = True
    Enabled = False
    Transparent = True
  end
  object badGuy1: TImage
    Left = 120
    Top = 72
    Width = 138
    Height = 194
    AutoSize = True
  end
  object badGuy2: TImage
    Left = 712
    Top = 72
    Width = 138
    Height = 194
    AutoSize = True
  end
  object coinAmountLabel: TLabel
    Left = 440
    Top = 16
    Width = 55
    Height = 125
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnFace
    Font.Height = -107
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object coin: TImage
    Left = 504
    Top = 320
    Width = 72
    Height = 81
    AutoSize = True
    Transparent = True
  end
  object endGameLabel2: TLabel
    Left = 232
    Top = 504
    Width = 473
    Height = 96
    Alignment = taCenter
    AutoSize = False
    Caption = 'to play'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -61
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
    Visible = False
  end
  object endGameLabel1: TLabel
    Left = 328
    Top = 448
    Width = 287
    Height = 72
    Caption = 'Tap Enter '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -61
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
    Visible = False
  end
  object heroTimerLeft: TTimer
    Enabled = False
    Interval = 30
    OnTimer = heroTimerLeftTimer
    Left = 32
    Top = 464
  end
  object heroTimerRight: TTimer
    Enabled = False
    Interval = 30
    OnTimer = heroTimerRightTimer
    Left = 96
    Top = 464
  end
  object heroTimerUp: TTimer
    Enabled = False
    Interval = 30
    OnTimer = heroTimerUpTimer
    Left = 64
    Top = 432
  end
  object heroTimerDown: TTimer
    Enabled = False
    Interval = 30
    OnTimer = heroTimerDownTimer
    Left = 64
    Top = 464
  end
  object badGuy1Timer: TTimer
    Interval = 19
    OnTimer = badGuy1TimerTimer
    Left = 16
    Top = 24
  end
  object badGuy2Timer: TTimer
    Interval = 19
    OnTimer = badGuy2TimerTimer
    Left = 64
    Top = 24
  end
  object heroTimer: TTimer
    Interval = 5
    OnTimer = heroTimerTimer
    Left = 112
    Top = 24
  end
  object heroLoseTimer: TTimer
    Enabled = False
    Interval = 20
    OnTimer = heroLoseTimerTimer
    Left = 16
    Top = 64
  end
end
