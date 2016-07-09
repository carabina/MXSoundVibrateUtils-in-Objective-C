//
//  ViewController.m
//  MXSoundVibrateUtils-Demo
//
//  Created by Meniny on 16/7/9.
//  Copyright © 2016年 Meniny. All rights reserved.
//

#import "ViewController.h"
#import "MXSoundVibrateUtils.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [[[MXSoundVibrateUtils alloc] initForDefault] play];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
