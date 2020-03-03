
#define PLAY_ADS_WORK_LOG @"PLAY_ADS_WORK_LOG" //获取工作日志的通知
#define PLAY_ADS_VERSION_STR  @"1.1.1"   //字符串版本号
#define PLAY_ADS_VERSION_NO   @"110"       //数字版本号，取字符串版本号去掉点

#import <Foundation/Foundation.h>
#import "PlayAdsRoleInfo.h"
#import "PlayAdsOrderInfo.h"


@interface PlayAdsManager : NSObject

//初始化接口，需要在app finishLaunch时调用，可以使用Qu_ickS_DK的productCode
+ (void)initPlayAdsWithProductCode:(NSString *)productCode;
//统计登录用户信息,如果没有用户名，username可以填uid
//账号登录成功，不是角色
+ (void)onLoginUid:(NSString *)uid username:(NSString *)name;
//游戏激活，按需调用，统计游戏激活观察点，不是打开app的设备数
//uid 账号uid，可以为nil
//roleId 角色id，可以为nil
+ (void)onActivationWithUserUid:(NSString *)uid roleId:(NSString *)roleId;
//统计用户注册，如果没有这个时机就不调用
+ (void)onRegisterUid:(NSString *)uid username:(NSString *)name;
//进入角色或者角色信息变化时调用
//isCreateRole表示该角色是否为刚刚创建的,默认否
+ (void)updateRoleInfo:(PlayAdsRoleInfo *)roleInfo isCreate:(BOOL)isCreateRole;
//统计充值，这里会关联角色信息
+ (void)congziOverInfo:(PlayAdsOrderInfo *)orderInfo roleInfo:(PlayAdsRoleInfo *)role;

@end
