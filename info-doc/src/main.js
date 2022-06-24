import { createApp } from 'vue';
import App from './App.vue';
import 'ant-design-vue/dist/antd.css';
import "tailwindcss/tailwind.css";

import {
    Button,
    Layout
}from "ant-design-vue"
const app = createApp(App);
app
  .use(Layout)
  .use(Button)
  .mount('#app');
