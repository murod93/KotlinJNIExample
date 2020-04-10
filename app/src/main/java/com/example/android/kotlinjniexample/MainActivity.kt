package com.example.android.kotlinjniexample

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity(), Example.ICallback {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val example = Example(this)

        btn_callback.setOnClickListener { example.sayHelloCallback() }

        btn_run_cpp.setOnClickListener { txt_result.text = example.sayHello() }

        btn_callback_num.setOnClickListener { example.runNumCallback() }
    }

    override fun onCallback() {
        txt_callback.text = "onCallback"
    }

    override fun onCallback(msg: String) {
        txt_callback.text = "onCallback($msg)"
    }

    override fun onCallback(num: Int) {
        txt_callback.text = "onCallback($num)"
    }
}
