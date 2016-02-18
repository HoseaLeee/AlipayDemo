//
//  ViewController.m
//  AlipayDemo
//
//  Created by Hosea on 16/2/17.
//  Copyright © 2016年 HoseaLee. All rights reserved.
//

#import "ViewController.h"
#import "AlipayHeader.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)alipayAction:(id)sender {
    
    [AlipayRequestConfig alipayWithTradeNO:@"123124342342" productName:@"商品名" productDescription:@"商品描述" amount:@"0.01" complete:^(NSDictionary *dictionary) {
        
        
        NSLog(@"支付结果：%@",dictionary);
        
    }];
}

@end
