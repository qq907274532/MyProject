package com.example.bec_004;

import java.io.File;
import java.io.IOException;

import android.os.Bundle;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

@SuppressLint("ShowToast")
public class MainActivity extends Activity 
{
	private Button BtnView;		// 创建浏览按钮对象
	private Button BtnRead;		// 创建读取按钮对象
	private Button BtnWrite;	// 创建写入按钮对象

    @Override
    protected void onCreate(Bundle savedInstanceState) 
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
    	// 查找对应View ID
        BtnView = (Button)findViewById(R.id.BtnView);
        BtnRead = (Button)findViewById(R.id.BtnRead);
        BtnWrite = (Button)findViewById(R.id.BtnWrite);
        
		BtnView.setOnClickListener(ListenView);
		BtnRead.setOnClickListener(ListenRead);
		BtnWrite.setOnClickListener(ListenWrite);

    }

	@Override
    public boolean onCreateOptionsMenu(Menu menu) 
    {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
	
	// 浏览按钮消息响应
	OnClickListener ListenView = new OnClickListener()
	{
		@Override
		public void onClick(View v) 
		{
			// TODO Auto-generated method stub
			Log.i("xiaokang", "浏览按钮被点击");
		}
	};
	
	// 读取文件按钮消息响应
	OnClickListener ListenRead = new OnClickListener()
	{
		@Override
		public void onClick(View v) 
		{
			// TODO Auto-generated method stub
			Log.i("xiaokang", "读取按钮被点击");

			File file = new File("/mnt/sdcard/text");
			Log.i("xiaokang", "文件对象被创建"); 

			if(!file.exists())
			{
				try 
				{
					file.createNewFile();		// 创建文件
					Log.i("xiaokang", "文件创建成功");
				} 
				catch (IOException e) 
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			else
			{
				Toast.makeText(MainActivity.this, "文件已经存在", 1000);
				Log.i("xiaokang", "文件创建失败");
			}
			
			file.canWrite();
		}
	};
	
	// 写入按钮消息响应
	OnClickListener ListenWrite = new OnClickListener()
	{
		@Override
		public void onClick(View v) 
		{
			// TODO Auto-generated method stub
			Log.i("xiaokang", "写入按钮被点击");
			//file.delete();	// 删除文件
		}
	};
}