<template>
  <div class="hello">
    <a-layout class="layout">
    <a-layout-header class="h-100 flex justify-center item-center">
      <div class="f-20 text-white">info-doc</div>
    </a-layout-header>
    <a-layout-content class="p-x-50 p-y-50">
      <div :style="{ background: '#fff', minHeight: '500px' }">Content</div>
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
  padding-bottom: 50px;
  padding-top: 50px;
}
.p-x-50{
  padding-left: 50px;
  padding-right: 50px;
}
</style>
