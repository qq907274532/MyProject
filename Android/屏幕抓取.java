package com.example.bec_032;

import java.io.IOException;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;

import android.hardware.Camera;
import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity 
{
	private Button BtnStart;

	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		BtnStart = (Button)findViewById(R.id.BtnStart);
		BtnStart.setOnClickListener(ListenView);
	}
	
	OnClickListener ListenView = new OnClickListener()
	{

		@Override
		public void onClick(View v) 
		{
			// TODO Auto-generated method stub

			new Thread()	// 创建线程实现截屏
			{
				@Override  
				public void run() 
				{  
					boolean bLoop = true;
					while(bLoop)
					{
//						if(isCameraCanUse())
//						{
//							Log.i("XK", "摄像头关闭");
//							continue;
//						}
//						else
//						{
//							Log.i("XK", "摄像头打开");
//						}
						
						Log.i("XK", "-----SCREENCAP START-----");
						Process sh = null;
						
						// 	获取系统Root权限
						try 
						{
							sh = Runtime.getRuntime().exec("su", null,null);
							Log.i("XK", "Root Succeed!");
						} 
						catch (IOException e) 
						{
							e.printStackTrace();
						}
						
						OutputStream os = sh.getOutputStream();	// 获取文件输出流
						
						// 调用 Screencap 截屏命令
						try 
						{
							os.write(("/system/bin/screencap -p " + "/sdcard/"+System.currentTimeMillis() +".png").getBytes("ASCII"));
							Log.i("XK", "Save as /sdcard/"+System.currentTimeMillis() + ".png");
						} 
						catch (UnsupportedEncodingException e) 
						{
							e.printStackTrace();
						}
						catch (IOException e) 
						{
							e.printStackTrace();
							Log.i("XK", "!!!Faill!!!");
						}
						
						try 
						{
							os.flush();
						} catch (IOException e) 
						{
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						try 
						{os.close();
						}
						catch (IOException e) 
						{
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						try 
						{
							sh.waitFor();
						} 
						catch (InterruptedException e) 
						{
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						
						// 每隔3秒循环一次
						try 
						{
							Thread.sleep(3000);
						} 
						catch (InterruptedException e) 
						{
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}  
			}.start();
			
		}
		
	};
	
	/*
	 * 		检测当前摄像头状态
	 * */
	public static boolean isCameraCanUse() 
	{    
		boolean canUse = true;    
		Camera mCamera = null;    
		try 
		{    
			mCamera = Camera.open(0);    
		} 
		catch (Exception e) 
		{    
			canUse = false;    
		}    
		if (canUse) 
		{    
			mCamera.release();    
			mCamera = null;    
		}    

		return canUse;    
	}
}
