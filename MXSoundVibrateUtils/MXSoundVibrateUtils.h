//
//  MXSoundVibrateUtils.h
//  WeiZi
//
//  Created by Meniny on 16/6/20.
//  Copyright © 2016年 YiBeacon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>

// See http://iphonedevwiki.net/index.php/AudioServices for more informations
/**
 * @brief 系统音效ID
 */
typedef enum : SystemSoundID {
    MXSystemSoundIDNewMail = 1000, // new-mail.caf, // new-mail.caf, // MailReceived
    MXSystemSoundIDMailSent = 1001, // mail-sent.caf, // mail-sent.caf, // MailSent
    MXSystemSoundIDVoicemailReceived = 1002, // Voicemail.caf, // Voicemail.caf, // VoicemailReceived
    MXSystemSoundIDReceivedMessage = 1003, // ReceivedMessage.caf, // ReceivedMessage.caf, // SMSReceived
    MXSystemSoundIDSentMessage = 1004, // SentMessage.caf, // SentMessage.caf, // SMSSent
    MXSystemSoundIDAlarm = 1005, // alarm.caf, // sq_alarm.caf, // CalendarAlert
    MXSystemSoundIDLowPower = 1006, // low_power.caf, // low_power.caf, // LowPower
    MXSystemSoundIDSMSReceived1 = 1007, // sms-received1.caf, // sms-received1.caf, // SMSReceived_Alert
    MXSystemSoundIDSMSReceived2 = 1008, // sms-received2.caf, // sms-received2.caf, // SMSReceived_Alert
    MXSystemSoundIDSMSReceived3 = 1009, // sms-received3.caf, // sms-received3.caf, // SMSReceived_Alert
    MXSystemSoundIDSMSReceived4 = 1010, // sms-received4.caf, // sms-received4.caf, // SMSReceived_Alert
    MXSystemSoundIDSMSReceivedVibrate = 1011, // -, // -, // SMSReceived_Vibrate
    MXSystemSoundIDSMSReceived01 = 1012, // sms-received1.caf, // sms-received1.caf, // SMSReceived_Alert
    MXSystemSoundIDSMSReceived5 = 1013, // sms-received5.caf, // sms-received5.caf, // SMSReceived_Alert
    MXSystemSoundIDSMSReceived6 = 1014, // sms-received6.caf, // sms-received6.caf, // SMSReceived_Alert
    MXSystemSoundIDVoiceMail = 1015,// NS_AVAILABLE_IOS(2.1) // Voicemail.caf, // Voicemail.caf, // -, // Available since 2.1
    MXSystemSoundIDTweetSent = 1016, // tweet_sent.caf, // tweet_sent.caf, // SMSSent, // Available since 5.0
    MXSystemSoundIDAnticipate = 1020, // Anticipate.caf, // Anticipate.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDBloom = 1021, // Bloom.caf, // Bloom.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDCalypso = 1022, // Calypso.caf, // Calypso.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDChooChoo = 1023, // Choo_Choo.caf, // Choo_Choo.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDDescent = 1024, // Descent.caf, // Descent.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDFanfare = 1025, // Fanfare.caf, // Fanfare.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDLadder = 1026, // Ladder.caf, // Ladder.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDMinuet = 1027, // Minuet.caf, // Minuet.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDNewsFlash = 1028, // News_Flash.caf, // News_Flash.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDNoir = 1029, // Noir.caf, // Noir.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDSherwood = 1030, // Sherwood_Forest.caf, // Sherwood_Forest.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDSpell = 1031, // Spell.caf, // Spell.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDSuspense = 1032, // Suspense.caf, // Suspense.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDTelegraph = 1033, // Telegraph.caf, // Telegraph.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDTiptoes = 1034, // Tiptoes.caf, // Tiptoes.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDTypewriters = 1035, // Typewriters.caf, // Typewriters.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDUpdate = 1036, // Update.caf, // Update.caf, // SMSReceived_Alert, // Available since 4.2
    MXSystemSoundIDUSSD = 1050, // ussd.caf, // ussd.caf, // USSDAlert
    MXSystemSoundIDSIMToolkitCallDropped = 1051, // SIMToolkitCallDropped.caf, // SIMToolkitCallDropped.caf, // SIMToolkitTone
    MXSystemSoundIDSIMToolkitGeneralBeep = 1052, // SIMToolkitGeneralBeep.caf, // SIMToolkitGeneralBeep.caf, // SIMToolkitTone
    MXSystemSoundIDSIMToolkitNegativeACK = 1053, // SIMToolkitNegativeACK.caf, // SIMToolkitNegativeACK.caf, // SIMToolkitTone
    MXSystemSoundIDSIMToolkitPositiveACK = 1054, // SIMToolkitPositiveACK.caf, // SIMToolkitPositiveACK.caf, // SIMToolkitTone
    MXSystemSoundIDSIMToolkitSMS = 1055, // SIMToolkitSMS.caf, // SIMToolkitSMS.caf, // SIMToolkitTone
    MXSystemSoundIDPINKeyPressedTink = 1057, // Tink.caf, // Tink.caf, // PINKeyPressed
    MXSystemSoundIDCtBusy = 1070, // ct-busy.caf, // ct-busy.caf, // AudioToneBusy, // There was no category for this sound before 4.0.
    MXSystemSoundIDCTCongestion = 1071, // ct-congestion.caf, // ct-congestion.caf, // AudioToneCongestion, // There was no category for this sound before 4.0.
    MXSystemSoundIDCTPathAck = 1072, // ct-path-ack.caf, // ct-path-ack.caf, // AudioTonePathAcknowledge, // There was no category for this sound before 4.0.
    MXSystemSoundIDCTError = 1073, // ct-error.caf, // ct-error.caf, // AudioToneError, // There was no category for this sound before 4.0.
    MXSystemSoundIDCTCallWaiting = 1074, // ct-call-waiting.caf, // ct-call-waiting.caf, // AudioToneCallWaiting, // There was no category for this sound before 4.0.
    MXSystemSoundIDCTKeytone2 = 1075, // ct-keytone2.caf, // ct-keytone2.caf, // AudioToneKey2, // There was no category for this sound before 4.0.
    MXSystemSoundIDScreenLocked = 1100, // lock.caf, // sq_lock.caf, // ScreenLocked
    MXSystemSoundIDScreenUnlocked = 1101, // unlock.caf, // sq_lock.caf, // ScreenUnlocked
    MXSystemSoundIDFailedUnlock = 1102, // -, // -, // FailedUnlock
    MXSystemSoundIDKeyPressedTink = 1103, // Tink.caf, // sq_tock.caf, // KeyPressed
    MXSystemSoundIDKeyPressedTock1 = 1104, // Tock.caf, // sq_tock.caf, // KeyPressed
    MXSystemSoundIDKeyPressedTock2 = 1105, // Tock.caf, // sq_tock.caf, // KeyPressed
    MXSystemSoundIDConnectedToPowerBeepBeep = 1106, // beep-beep.caf, // sq_beep-beep.caf, // ConnectedToPower
    MXSystemSoundIDRingerSwitchIndication = 1107, // RingerChanged.caf, // RingerChanged.caf, // RingerSwitchIndication
    MXSystemSoundIDCameraShutter = 1108, // photoShutter.caf, // photoShutter.caf, // CameraShutter
    MXSystemSoundIDShake = 1109, // shake.caf, // shake.caf, // ShakeToShuffle, // Available since 3.0
    MXSystemSoundIDJBLBegin = 1110, // jbl_begin.caf, // jbl_begin.caf, // JBL_Begin, // Available since 3.0
    MXSystemSoundIDJBLConfirm = 1111, // jbl_confirm.caf, // jbl_confirm.caf, // JBL_Confirm, // Available since 3.0
    MXSystemSoundIDJBLCancel = 1112, // jbl_cancel.caf, // jbl_cancel.caf, // JBL_Cancel, // Available since 3.0
    MXSystemSoundIDBeginRecord = 1113, // begin_record.caf, // begin_record.caf, // BeginRecording, // Available since 3.0
    MXSystemSoundIDEndRecord = 1114, // end_record.caf, // end_record.caf, // EndRecording, // Available since 3.0
    MXSystemSoundIDJBLAmbiguous = 1115, // jbl_ambiguous.caf, // jbl_ambiguous.caf, // JBL_Ambiguous, // Available since 3.0
    MXSystemSoundIDJBLNoMath = 1116, // jbl_no_match.caf, // jbl_no_match.caf, // JBL_NoMatch, // Available since 3.0
    MXSystemSoundIDBeginVideoRecord = 1117, // begin_video_record.caf, // begin_video_record.caf, // BeginVideoRecording, // Available since 3.0
    MXSystemSoundIDEndVideoRecord = 1118, // end_video_record.caf, // end_video_record.caf, // EndVideoRecording, // Available since 3.0
    MXSystemSoundIDVCInvitationAccepted = 1150, // vc~invitation-accepted.caf, // vc~invitation-accepted.caf, // VCInvitationAccepted, // Available since 4.0
    MXSystemSoundIDVCRinging = 1151, // vc~ringing.caf, // vc~ringing.caf, // VCRinging, // Available since 4.0
    MXSystemSoundIDVCEnded = 1152, // vc~ended.caf, // vc~ended.caf, // VCEnded, // Available since 4.0
    MXSystemSoundIDVCCallWaiting = 1153, // ct-call-waiting.caf, // ct-call-waiting.caf, // VCCallWaiting, // Available since 4.1
    MXSystemSoundIDVCCallUpgrade = 1154, // vc~ringing.caf, // vc~ringing.caf, // VCCallUpgrade, // Available since 4.1
    MXSystemSoundIDTouchToneDTMF0 = 1200, // dtmf-0.caf, // dtmf-0.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF1 = 1201, // dtmf-1.caf, // dtmf-1.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF2 = 1202, // dtmf-2.caf, // dtmf-2.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF3 = 1203, // dtmf-3.caf, // dtmf-3.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF4 = 1204, // dtmf-4.caf, // dtmf-4.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF5 = 1205, // dtmf-5.caf, // dtmf-5.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF6 = 1206, // dtmf-6.caf, // dtmf-6.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF7 = 1207, // dtmf-7.caf, // dtmf-7.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF8 = 1208, // dtmf-8.caf, // dtmf-8.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMF9 = 1209, // dtmf-9.caf, // dtmf-9.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMFStar = 1210, // dtmf-star.caf, // dtmf-star.caf, // TouchTone
    MXSystemSoundIDTouchToneDTMFPound = 1211, // dtmf-pound.caf, // dtmf-pound.caf, // TouchTone
    MXSystemSoundIDHeadsetStartCall = 1254, // long_low_short_high.caf, // long_low_short_high.caf, // Headset_StartCall
    MXSystemSoundIDHeadsetRedial = 1255, // short_double_high.caf, // short_double_high.caf, // Headset_Redial
    MXSystemSoundIDHeadsetAnswerCall = 1256, // short_low_high.caf, // short_low_high.caf, // Headset_AnswerCall
    MXSystemSoundIDHeadsetEndCall = 1257, // short_double_low.caf, // short_double_low.caf, // Headset_EndCall
    MXSystemSoundIDHeadsetCallWaitingActions = 1258, // short_double_low.caf, // short_double_low.caf, // Headset_CallWaitingActions
    MXSystemSoundIDHeadsetTransitionEnd = 1259, // middle_9_short_double_low.caf, // middle_9_short_double_low.caf, // Headset_TransitionEnd
    MXSystemSoundIDSystemSoundPreviewVoicemail = 1300, // Voicemail.caf, // Voicemail.caf, // SystemSoundPreview
    MXSystemSoundIDSystemSoundPreviewReceivedMessage = 1301, // ReceivedMessage.caf, // ReceivedMessage.caf, // SystemSoundPreview
    MXSystemSoundIDSystemSoundPreviewNewMail = 1302, // new-mail.caf, // new-mail.caf, // SystemSoundPreview
    MXSystemSoundIDSystemSoundPreviewMailSent = 1303, // mail-sent.caf, // mail-sent.caf, // SystemSoundPreview
    MXSystemSoundIDSystemSoundPreviewAlarm = 1304, // alarm.caf, // sq_alarm.caf, // SystemSoundPreview
    MXSystemSoundIDSystemSoundPreviewLock = 1305, // lock.caf, // sq_lock.caf, // SystemSoundPreview
    MXSystemSoundIDKeyPressClickPreviewTock = 1306, // Tock.caf, // sq_tock.caf, // KeyPressClickPreview, // The category was SystemSoundPreview before 3.2.
    MXSystemSoundIDSMSReceivedSelectionSMSReceived1 = 1307, // sms-received1.caf, // sms-received1.caf, // SMSReceived_Selection
    MXSystemSoundIDSMSReceivedSelectionSMSReceived2 = 1308, // sms-received2.caf, // sms-received2.caf, // SMSReceived_Selection
    MXSystemSoundIDSMSReceivedSelectionSMSReceived3 = 1309, // sms-received3.caf, // sms-received3.caf, // SMSReceived_Selection
    MXSystemSoundIDSMSReceivedSelectionSMSReceived4 = 1310, // sms-received4.caf, // sms-received4.caf, // SMSReceived_Selection
    MXSystemSoundIDSMSReceivedSelectionSMSReceivedVibrate = 1311, // -, // -, // SMSReceived_Vibrate
    MXSystemSoundIDSMSReceivedSelectionSMSReceived01 = 1312, // sms-received1.caf, // sms-received1.caf, // SMSReceived_Selection
    MXSystemSoundIDSMSReceivedSelectionSMSReceived5 = 1313, // sms-received5.caf, // sms-received5.caf, // SMSReceived_Selection
    MXSystemSoundIDSMSReceivedSelectionSMSReceived6 = 1314, // sms-received6.caf, // sms-received6.caf, // SMSReceived_Selection
    MXSystemSoundIDSystemSoundPreviewVoicemail2 = 1315, // Voicemail.caf, // Voicemail.caf, // SystemSoundPreview, // Available since 2.1
    MXSystemSoundIDSMSReceivedSelectionAnticipate = 1320, // Anticipate.caf, // Anticipate.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionBloom = 1321, // Bloom.caf, // Bloom.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionCalypso = 1322, // Calypso.caf, // Calypso.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionChooChoo = 1323, // Choo_Choo.caf, // Choo_Choo.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionDescent = 1324, // Descent.caf, // Descent.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionFanfare = 1325, // Fanfare.caf, // Fanfare.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionLadder = 1326, // Ladder.caf, // Ladder.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionMinuet = 1327, // Minuet.caf, // Minuet.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionNewsFlash = 1328, // News_Flash.caf, // News_Flash.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionNoir = 1329, // Noir.caf, // Noir.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionSherwood = 1330, // Sherwood_Forest.caf, // Sherwood_Forest.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionSpell = 1331, // Spell.caf, // Spell.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionSuspense = 1332, // Suspense.caf, // Suspense.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionTelegraph = 1333, // Telegraph.caf, // Telegraph.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionTiptoes = 1334, // Tiptoes.caf, // Tiptoes.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionTypewriters = 1335, // Typewriters.caf, // Typewriters.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDSMSReceivedSelectionUpdate = 1336, // Update.caf, // Update.caf, // SMSReceived_Selection, // Available since 4.2
    MXSystemSoundIDRingerVibeChanged = 1350, // -, // -, // RingerVibeChanged
    MXSystemSoundIDSilentVibeChanged = 1351, // -, // -, // SilentVibeChanged
    MXSystemSoundIDVibrate = 4095, // -, // -, // Vibrate
} MXSystemSoundID;

#define MXSystemSoundIDDefault MXSystemSoundIDSMSReceived1

@interface MXSoundVibrateUtils : NSObject

/**
 *  @brief  为震动效果初始化
 *
 *  @return self
 */
- (instancetype)initForVibrate;

/**
 *  @brief  为三全音效果初始化
 *
 *  @return self
 */
- (instancetype)initForDefault;

/**
 *  @brief  为播放系统音效初始化
 *
 *  @param soundID 系统音效ID
 *
 *  @return MXSoundVibrateUtils 实例
 */
- (instancetype)initForPlayingSystemSoundEffectWithSoundID:(SystemSoundID)aSoundID;

/**
 *  @brief  为播放系统音效初始化
 *
 *  @param soundID 系统音效ID
 *
 *  @return MXSoundVibrateUtils 实例
 */
- (instancetype)initForPlayingSystemSoundEffectWithSoundIDEnum:(MXSystemSoundID)aSoundID;

/**
 *  @brief  为播放系统音效初始化
 *
 *  @param resourceName 系统音效名称
 *  @param type 系统音效类型
 *
 *  @return MXSoundVibrateUtils 实例
 */
- (instancetype)initForPlayingSystemSoundEffectWithResourceName:(NSString *)resourceName
                                                         ofType:(NSString *)type;
/**
 *  @brief  为播放特定的音频文件初始化
 *
 *  @param filePath 音频文件路径
 *
 *  @return MXSoundVibrateUtils 实例
 */
- (instancetype)initForPlayingSoundEffectWithFilePath:(NSString *)filePath;

/**
 *  @brief  为播放特定的音频文件初始化
 *
 *  @param fileName 音频文件名
 *
 *  @return MXSoundVibrateUtils 实例
 */
- (instancetype)initForPlayingSoundEffectWithFileName:(NSString *)fileName;

/**
 *  @brief  播放音效
 */
- (void)play;
@end
