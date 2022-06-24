import { createApp } from 'vue';
import App from './App.vue';
import 'ant-design-vue/dist/antd.css';
import "tailwindcss/tailwind.css";

import {
    Button,
    Layout,
    Space
}from "ant-design-vue"
const app = createApp(App);
app
  .use(Layout)
  .use(Button)
  .use(Space)
  .mount('#app');
