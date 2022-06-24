<template>
  <div class="hello">
    <a-layout class="layout">
    <a-layout-header class="h-100 flex justify-center item-center">
      <div class="f-20 text-white">info-doc</div>
    </a-layout-header>
    <a-layout-content class="p-x-50 p-y-50">
      <div :style="{ background: '#fff', minHeight: '600px' }">
        <div class="grid w-v10">
            <a-button type="primary" class="float-r m-t-20 m-l-10" ghost v-for="item,index in buttonList" :key="index" @click="item.status = !item.status">{{item.status? item.text1 : item.text2}}</a-button>
        </div>
      </div>
    </a-layout-content>
    <a-layout-footer style="text-align: center">
      <div>BISTU-OSSDT-2022 created by '大摆钟组'</div>
      <github-outlined :style="{ fontSize: '30px', marginTop: '10px' }" @click="togithub"/>
    </a-layout-footer>
  </a-layout>
  </div>
</template>

<script setup>
import { GithubOutlined } from "@ant-design/icons-vue";
import { ref } from "vue";

const buttonList = ref([
  {
    text1:'过滤时间on',
    text2:'过滤时间off',
    status:false
  },
  {
    text1:'过滤qq号on',
    text2:'过滤qq号off',
    status:false
  },
  {
    text1:'过滤名称on',
    text2:'过滤名称off',
    status:false
  },
  {
    text1:'过滤图片on',
    text2:'过滤图片off',
    status:false
  },
]);
</script>

<style scoped>
.f-20{
  font-size: 40px;
}
.text-white{
  color:white;
}
.h-100{
  height: 100px;
}
.flex{
  display: flex;
}
.justify-center{
  justify-content: center;
}
.item-center{
  align-items: center;
}
.p-y-50{
  padding-bottom: 15px;
  padding-top: 50px;
}
.p-x-50{
  padding-left: 50px;
  padding-right: 50px;
}
.w-v10{
  width: 10vw;
}
.w-100c{
  width: 100%;
}
.float-r{
  float: right;
}
.grid{
  display: grid;
}
.m-t-20{
  margin-top:20px;
}
.m-l-10{
  margin-left: 10px;
}
</style>
